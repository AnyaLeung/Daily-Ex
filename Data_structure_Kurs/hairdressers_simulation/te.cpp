#include <iostream>

using namespace std;

int* test(int *h){
    h = new int[5];
    for(int i=0; i<5; i++){
        *h = i;
        cout << *h << " " << endl;
    }
   return h; 
}

int main(void){
    int *h;
    h = new int[5];
    h = test(h);
    for(int i=0; i<5; i++){
        cout << *h << " ";
    }
    return 0;
}
