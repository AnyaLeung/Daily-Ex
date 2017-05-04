#include <stdio.h>

void bubble_sort(int arr[], int total);
void selection_sort(int a[], int total);
void merge(int c[], int *nc, int a[], int na, int b[], int nb);

int main(void){
    int arr_1[10] = {0};
    int arr_2[10] = {0};
    int tmp1 = 0, tmp2 = 0;
    int max = 0;
    int sorted[100] = {0};
    int k = 0;
    int *nc = 0;
    
    printf("enter first array: \n");
    for(int i=0; i<10; i++){
        scanf("%d", &arr_1[i]);
    }
    printf("enter another array: \n");
    for(int i=0; i<10; i++){
        scanf("%d", &arr_2[i]);
    }
    
    bubble_sort(arr_1, 10);
    selection_sort(arr_2, 10);
    merge(sorted, nc, arr_1, 10, arr_2, 10);

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
int merge(int sorted[],  int a[], int ano, int b[], int bno){
    int a_count = 0, b_count = 0 , c_count = 0;
    while(a_count<ano&& b_count<bno) 
        a[a_count]>b[b_count]? sorted[c_count++]=a[a_count++]: sorted[c_count++]=b[b_count++];

    return c_count;
}
*/

void merge(int c[], int *nc, int a[], int na, int b[], int nb){
    int cursora, cursorb, cursorc;

    cursora=cursorb=cursorc=0;

    while((cursora<na)&&(cursorb<nb))
        if (a[cursora]<=b[cursorb])
            c[cursorc++]=a[cursora++];
        else
            c[cursorc++]=b[cursorb++];

    while(cursora<na)
        c[cursorc++]=a[cursora++];

    while(cursorb<nb)
        c[cursorc++]=b[cursorb++];

    *nc = cursorc;
}
