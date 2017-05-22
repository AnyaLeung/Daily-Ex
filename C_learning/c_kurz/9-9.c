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
    int temp = 0;
    
    printf("被减数： ");
    gets(a);
    printf("减数： ");
    gets(b);
    
    lena = strlen(a);
    lenb = strlen(b);
    
    Judge(lena, lenb, a, b);
    
    if(sign=='-'){
        temp = lena;
        lena = lenb;
        lenb = temp;
    }

    for(i=0; i<lena; i++){
        res[lena-i-1] = (int)(a[lena-i-1]-'0') - (int)(b[lenb-i-1]-'0');
        if(res[lena-i-1]>10) res[lena-i-1] -= (int)'0';
    }
    
    for(j=lena-1; j>=0; j--){
        if(res[j]<0){
            res[j-1] --;
            res[j] += 10;
        }
    } //借位
  
    if(sign=='+') ;
    else printf("-"); //打印符号
    
    for(k=0; k<lena; k++){
        printf("%d", res[k]);
    }
    
    return 0;
}

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
