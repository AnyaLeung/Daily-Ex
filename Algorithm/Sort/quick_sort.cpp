#include <iostream>

using namespace std;

void Swap(int &a, int &b) {
    int tmp = 0;
    tmp =  a;
    a = b;
    b = tmp;
}

int Partition() {
    int i = 0, j = len - 1 ;
    int *p = arr;
    int pivot = arr[j / 2];

    while(i<=j) {
       if(*p>pivot) {
            Swap(*p, arr[j--]);
       }
       p++;
    }
}

int* quick_sort(int arr[], int len){
}

int main(void) {

    return 0;
}
