#include <iostream>

using namespace std;

void bubble_sort(int arr[], int total);

int main(void){
    int a[10] = {0};
    printf("before sort: ");
    for(int j=0; j<10; j++){
        a[j] = j + 1;
        printf("%d", a[j]);
    }

    bubble_sort(a, 10);
    printf("\nafter sort:  ");
    for(int i=0; i<10; i++){
        printf("%d", a[i]);
    }
    return 0;
}

void bubble_sort(int arr[], int total){
    int tmp = 0;
    for(int i=0; i<total-1; i++){
        for(int j=0; j<total-1-i; j++){
            if(arr[j+1]>arr[j]){
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
//递减，并逐渐把小的固定最后
