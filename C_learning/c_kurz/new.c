#include <stdio.h>

int main(void){
    int a[3][3] = {0};
    int max = 0;
    int sort[3] = {0};
    int min = 10;
    int tmp = 0;
    int col[3] = {0};
    int row[3] = {0};
    int rem = 0;

    for(int j=0; j<3; j++){
        for(int i=0; i<3; i++){
            scanf("%d", &a[j][i]);
        }
    }

    for(int j=0; j<3; j++){
        for(int i=0; i<3; i++){
            if(a[j][i]>max){
                max = a[j][i];
                tmp = i;
            }
            min = max;
            for(int m=0; m<3; m++){
                if(tmp)
            }
        }
    }

    printf("max_min:%d", min);

    return 0;
}
