#include <stdio.h>
#include <string.h>

void shrlshif(char *s, int n);

int main(void){
    char input[100];
    int n = 0;
    gets(input);
    printf("enter n:");
    scanf("%d", &n);
    shrlshif(input, n);

    return 0;
}

void shrlshif(char *s, int n){
    char tmp;
    int len = 0;;
    len = strlen(s);
    for(int i=0; i<n; i++){
        tmp = s[0];
        strncpy(s, s+1, 1);
        s[len-1] = tmp;
   }
}
