/*add a list of integers and use of sentinel*/

#include <iostream>
#include "genlib.h" //这是什么鬼。。？
#include "simpio.h"

const int SENTINEL = 0;

int main(void){
    cout << "This program adds a list of numbers." << endl;
    cout << "Use" << SENTINEL << "to signal the end." << endl;
    int total = 0;

    while(true){
        cout << " ? ";
        int value = GetInteger();
        if (value == SENTINEL) break;
        total += value;
    }
    cout << "The total is" << total << endl;
    return 0;
}

