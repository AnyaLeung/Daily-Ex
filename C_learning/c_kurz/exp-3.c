#include <stdio.h>

int main(void){
    int no = 0;
    int div[5]= {0};
    int i = 0;
    int j = 0;
    int flag = 1; //0-->不是回文数，1-->是回文数

    scanf("%d", &no);

    while(no>99999|| no<10000){
        printf("wrong number, enter again: ");
        scanf("%d", &no);
    }

    while(no!=0){
        div[i] = no % 10;
        no /= 10;
        i++;
    }

    while(j<3&& flag==1){
        if(div[j]==div[4-j]) ;
        else{
          flag = 0;
        }
        j++;
    }

    if(flag) printf("这是一个回文数");
    else printf("这不是一个回文数");

    return 0;
}
