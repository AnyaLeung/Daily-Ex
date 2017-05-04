#include <iostream>

using namespace std;

void selection_sort(int a[], int total);

int main(void){
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    selection_sort(a, 10);
    for(int i=0; i<10; i++){
        printf("%d", a[i]);
    }
    return 0;
}

void selection_sort(int a[], int total){
    int max_index = 0, tmp = 0;
    for(int i=0; i<total-1; i++){
        max_index = i;
        for(int j=i+1; j<total; j++){
            if(a[max_index]>a[j]) max_index = j;

            tmp = a[max_index];      
            a[max_index] = a[i]; 
            a[i] = tmp; //when ends a line, exchage between a[max] and **a[i]**
        } 
    }
}
/*
 * basic thought:
 * 把整个数组过很多遍，第一遍找出最大的和第一个换，第二遍找第二大的和第二个换…
 * 以此类推
 *
 * 第n趟结束的时候，把这一趟最大（小）的和第n个换
 */
