#include <iostream>

using namespace std;

void selection_sort(int a[], int total);

int main(void){
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    selection_sort(a, 10);
    for(int i=0; i<10; i++){
        printf("%d", a[i]);
    }
    return 0;
}

void selection_sort(int a[], int total){
    int max = 0, tmp = 0; //index
    for(int i=0; i<total-1; i++){
        max = i;
        for(int j=i+1; j<total; j++){
            if(a[j]>a[max]) max=j;
        }
        //在这一趟最大的放最前面，exchange
        tmp = a[max];
        a[max] = a[i];
        a[i] = tmp;
    }
}
