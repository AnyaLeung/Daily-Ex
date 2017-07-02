#include <iostream>
#include <string.h>
#include "rect.h"
using namespace std;

int main(void){
    Rectangle rec1(5, 4); //create an object with constructor 1
    Rectangle rec2('a');  //create an object with constructor 1
    rec1.ReadInfo();
    rec1.Show();
    rec1.DrawRec(); //draw rec1

    cout << endl;
    Rectangle rec3(rec1, 0);
    cout << "rec3" << endl;
    rec3.Show();
 
    cout << endl;
    Rectangle rec4(rec3, 1);
    cout << "rec4" << endl;
    rec4.Show();


    return 0;
}
