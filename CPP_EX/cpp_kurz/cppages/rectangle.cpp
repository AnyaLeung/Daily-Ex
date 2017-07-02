#include <iostream>
#include "rectangle.h"

using namespace std;

int main(void){
    int m = 0, n = 0;
    char a;
    char sen[100] = {'\0'};

    cout << "enter length: ";
    cin >> m;
    cout << "enter height: ";
    cin >> n;


    cout << "enter a letter for next rec: ";
    cin >> a;

    Rectangle rec1(m, n);
    Rectangle rec2gle(a);

    rec1.DrawRec();

    Rectangle rec3(rec1);
    cout << "rec3 " ;
    rec1.ReadInfo();
    rec1.Show();


    return 0;
}
