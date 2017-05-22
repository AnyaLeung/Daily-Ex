#include <stdio.h>
#include <string.h>

char sign;

void Judge(int lena, int lenb, char *a, char *b);

int main(void){
    char a[1000]; //被减数
    char b[1000]; //减数
    int res[1000] = {0};
    int lena = 0, lenb = 0;
    int i = 0, j = 0, k = 0;
    int flag = 0;

    printf("被减数： ");
    gets(a);
    printf("减数： ");
    gets(b);

    lena = strlen(a);
    lenb = strlen(b);

    Judge(lena, lenb, a, b);

    for(; i<lena; i++){
        res[lena-i-1] = (int)(a[lena-i-1]-'0') - (int)(b[lenb-i-1]-'0'); 
        if(res[lena-i-1]>9) res[lena-i-1] -= 48;
    }

    for(; j<lena; j++){
        if(res[lena-j-1]<0){
            res[lena-j-2] --;
            res[lena-j-i] += 10;
        }
    } //借位

    if(sign=='+') ;
    else printf("-"); //打印符号

   for(; k<lena; k++){
       printf("%d", res[k]);
   }

    return 0;
}
/*
void Judge(int lena, int lenb, char *a, char *b){ //判断减数和被减数的大小关系
    char *tmp;
    if(lena>=lenb&& strcmp(a,b)>=0) sign = '+';
    else {
        sign = '-';
        strcpy(tmp, a);
        strcpy(a, b);
        strcpy(b, tmp);
    } 
}
*/

void Judge(int lena, int lenb, char *a, char *b){ //判断减数和被减数的大小关系
    char *tmp;
    if(lena<lenb){
        sign = '-';
        strcpy(tmp, a);
        strcpy(a, b);
        strcpy(b, tmp);
        }
    else if(lena==lenb&& strcmp(a, b)<0){
        sign = '-';
        strcpy(tmp, a);
        strcpy(a, b);
        strcpy(b, tmp);
    }
    else sign = '+';
}
