#include <stdio.h>
#include <string.h>

void strlshif(char *s, int n){
   int len = 0;
   int i = 0;
   char tmp;

   len = strlen(s);
   for(i=0; i<n; i++){
       tmp = s[0]; //第一个的值存起来
       strncpy(s, s+1, len-1); //前一个的值等于后一个, 每次移动前(len-1)
       s[len-1] = tmp; //把第一个赋值给最后一个
   }
}

int main(void){
    char input[100];
    int n = 0;

    scanf("%s", input);
    printf("n: ");
    scanf("%d", &n);

    strlshif(input, n);

    printf("%s", input);
    return 0;
}
