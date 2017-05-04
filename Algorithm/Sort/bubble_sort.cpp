#include <iostream>

using namespace std;

void bubble_sort(int arr[], int total);

int main(void){
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubble_sort(a, 10);
    for(int i=0; i<10; i++){
        printf("%d", a[i]);
    }
    return 0;
}

void bubble_sort(int arr[], int total){
    int tmp = 0;
    for(int i=0; i<total-1; i++){
        for(int j=0; j<total-1-i; j++){
            if(arr[j+1]<arr[j]){
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
