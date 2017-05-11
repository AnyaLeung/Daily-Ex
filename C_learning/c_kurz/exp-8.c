#include <stdio.h>

bool Like[5][5] = {
    {0, 0, 1, 1, 0}, 
    {1, 1, 0, 0, 1}, 
    {0, 1, 1, 0, 1}, 
    {0, 0, 0, 1, 0}, 
    {0, 1, 0, 0, 1}
};
int book[5] = {0}; //0 for not attr
int n = 0;

void Try(int i);

int main(void){
   Try(0);
   return 0;
}

void Try(int i){
    int j = 0, k = 0;
    for(j=0; j<5; j++){
        if(Like[i][j]&& book[j]==0){
            book[j] = i + 1; //give book_j to ith person
            if(i==4){
                n++;            
                printf("方案%d:\n", n);
                for(k=0; k<5; k++){
                    printf("第%d本书分给%c\n", k, (char)(book[k]-1+'A'));
                }
                printf("\n");
            }
            else
                Try(i + 1);
            book[j] = 0;
        }
    }
}

