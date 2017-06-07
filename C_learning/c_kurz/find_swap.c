#include <stdio.h>

#define size 10

void find_and_swap(int no[]);

int main(void){
    int no[size] = {0};
    int tmp = 0;
    int i = 0, j = 0;

    for(; i<size; i++){
        scanf("%d", &no[i]);
    }

    find_and_swap(no);

        printf("after order: ");
    for(; j<size; j++){
        printf("%d ", no[j]);
    }
    return 0;
}

void find_and_swap(int no[]){
    int max_index = 0; 
    int min_index = 0;
    //   int rem1 = 0;
    //   int rem2 = 0;
    int i = 0;
    int tmp = 0;

    for(; i<size; i++){
        if(no[i]>no[max_index]){
            max_index = i;
        }
        if(no[i]<no[min_index]){
            min_index = i;
        }
    }

    tmp = no[0];
    no[0] = no[max_index];
    no[max_index] = tmp;

    tmp = no[9];
    no[9] = no[min_index];
    no[min_index] = tmp;
}
