#include <stdio.h>
#include <string.h>
//word of palindrome
//回文

int judge(char str[]){
    char *start, *end;
    int len = 0;
    int flag = 0;
    len = strlen(str);
    start = &str[0];
    end = &str[len-1];
    while(*start==*end){
        start++;
        end--;
        if(start>=end){
            flag = 1;
        }
    }
    return flag;
}

int main(void){
    char str[100];
    gets(str);
    if(judge(str)) printf("yes!");
    else printf("no!");

    return 0;
}
