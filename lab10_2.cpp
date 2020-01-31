#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	return rand() % 13 + 1;
}

int calScore(int x,int y,int z){
	int sum;
	sum = x + y + z;
	return sum%10;
}

int findYugiAction(int s){
	if(s == 9) return 2; // Yugi will definitely stay (2) when current score (s) is equal to 9
	else if(s < 6) return 1; // Yugi will definitely draw (1) when current score (s) is less than 6
	else{
        srand(time(0));
        s = rand()%100 + 1;
        if(s <= 69) return 1;
        else return 2;
	}
}

void checkWinner(int p, int y){

	cout <<              "\n---------------------------------\n";
	if(p == y) cout <<     "|             Draw!!!           |"; // when p is equal to y
	if(p > y)  cout <<     "|         Player wins!!!        |"; // when p is greater than y
	if(p < y)  cout <<     "|          Yugi wins!!!         |"; // when p is less than y
	cout <<              "\n---------------------------------\n";
}

int main(){
	srand(time(0));
	int playerScore , yugiScore , playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};

	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(cardScores[playerCards[0]],cardScores[playerCards[1]],cardScores[playerCards[2]]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction != 1 && playerAction != 2);
	if(playerAction == 1){
		int playerCards[3] = {drawCard(), drawCard(), drawCard()};
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: " << cardNames[playerCards[2]] << "\n";
		playerScore += calScore(0,0,cardScores[playerCards[2]]);
		if(playerScore >=10 && playerScore < 20) playerScore -= 10;
		else if(playerScore >=20) playerScore -= 20;
		cout << "Your new score: " << playerScore << "\n";

	}else if(playerAction == 2){
	cout << "------------ Turn end -------------------\n\n";
	}

	int yugiCards[3] = {drawCard(), drawCard(), 0};

	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
	yugiScore = calScore(cardScores[yugiCards[0]],cardScores[yugiCards[1]],cardScores[yugiCards[2]]);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		int yugiCards[3] = {drawCard(), drawCard(), drawCard()};
		cout << "Yugi draws the 3rd card!!!\n";
		cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]] << "\n";
		yugiScore += calScore(0,0,cardScores[yugiCards[2]]);
		if(yugiScore >=10 && yugiScore < 20) yugiScore -= 10;
		else if(yugiScore >=20) yugiScore -= 20;
		cout << "Yugi's new score: " << yugiScore << "\n";
	}else{
	cout << "------------ Turn end -------------------\n";
	}

	checkWinner(playerScore,yugiScore);
}

