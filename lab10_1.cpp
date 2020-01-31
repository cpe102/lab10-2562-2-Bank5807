#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    srand(time(0));
    int i = rand() % 9 + 1;
    string j = "";
    cout << "Press Enter 3 times to reveal your future." << endl;
    cin.get();
    cin.get();
    cin.get();
    switch(i){
        case 1: j = "A";  break;
        case 2: j = "B+"; break;
        case 3: j = "B";  break;
        case 4: j = "C+"; break;
        case 5: j = "C";  break;
        case 6: j = "D+"; break;
        case 7: j = "D";  break;
        case 8: j = "F";  break;
        case 9: j = "W";  break;
        default: cout << "good luck"; return 0;
    }
    cout << "You will get " << j << " in this 261102." << endl;
    return 0;
}
