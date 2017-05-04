#include <stdio.h>

int main(void){
    int arr_1[10] = {0};
    int arr_2[10] = {0};
    int tmp1 = 0, tmp2 = 0;
    int max = 0;
    int k = 0;
    
    printf("enter first array: \n");
    for(int i=0; i<10; i++){
        scanf("%d", &arr_1[i]);
    }
    printf("enter another array: \n");
    for(int i=0; i<10; i++){
        scanf("%d", &arr_2[i]);
    }
    
    for(int m=1; m<10; m++){
        for(int n=0; n<10-m; n++){
            if(arr_1[n]<arr_1[n+1]){
                tmp1 = arr_1[n];
                arr_1[n] = arr_1[n+1];
                arr_1[n+1] = tmp1;
            }
        }
    } //bubble sort for arr_1

    for(int s=0; s<9; s++){
        max_index = s;
        for(int l=s+1; s<10; l++){
            if(arr_2[l]>arr_2[max_index]) {
                max_index = l;
                tmp2 = arr_2[s];
                arr_2[s] = arr_2[max_index];
                arr_2[max_index] = tmp2;
            }
        }
    }

    
    for(int i=0; i<9; i++){
        k = i;
        for(int j=i+1; j<10; i++){
            if(arr_2[k]<arr_2[j]){
                max = j;
                tmp2 = arr_2[i];
                arr_2[i] = arr_2[k];
                arr_2[k] = tmp2;
            }
        }
    } //为啥不行啊啊啊啊啊啊啊啊啊啊我的选择排序有毒啊啊啊啊啊

    int sort[20] = {0};
    int count1 = 0, count2 = 0;
    (arr_1[count1]>arr_1[count2])? sort[1] = arr_1[count1] count1++; : arr_2[count2]count2++;
    if(count1==9) put another allin;
    if(count2==9) put another allin;

    return 0;
}
