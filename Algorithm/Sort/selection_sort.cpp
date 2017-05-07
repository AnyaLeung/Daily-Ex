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
    int min_index = 0, tmp = 0;
    for(int i=0; i<total-1; i++){
        min_index = i;
        for(int j=i+1; j<total; j++){
            if(a[min_index]<a[j]) min_index = j;

            tmp = a[min_index];      
            a[min_index] = a[i]; 
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
