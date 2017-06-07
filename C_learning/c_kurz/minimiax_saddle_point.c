#include <stdio.h>

bool colmin(int c[][3], int row, int col);
bool rowmax(int c[][3], int row, int col);
void find(int c[][3], int cl, int rl);

int main(void){
    int c[3][3] = {0};
    int i = 0, j = 0;
    
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            scanf("%d", &c[i][j]);
        }
    }
    
    find(c, 3, 3);
    
    return 0;
}

void find(int c[][3], int cl, int rl) {
    int i = 0, j = 0;
    
    for(i=0; i<cl; i++) {
        for(j=0; j<rl; j++) {
            if(rowmax(c, i, j)&&colmin(c, i, j)){
                printf("saddle point: %d\n", c[i][j]);
            }
        }
    }
}

bool rowmax(int c[][3], int row, int col) {
    int max = c[row][col];
    int i = 0;
    for(i=0; i<3; i++) {
        if(c[row][i]>max) {
            return false;
        }
    }
    return true;
}

bool colmin(int c[][3], int row, int col) {
    int min = c[row][col];
    int i = 0;
    for(i=0; i<3; i++) {
        if(c[i][col]<min) {
            return false;
        }
    }
    return true;
}
