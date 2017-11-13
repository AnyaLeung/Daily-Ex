#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int main(void){
    srand(time(0));
    int r = rand() % (3 - 0);
    cout << r;
    return 0;
}
