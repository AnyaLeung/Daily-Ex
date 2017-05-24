#include <stdio.h>
#include <string.h>

char sub[100];

void substr(char *s, int startloc, int len){
    int i = 0;
    
   // printf("%s", s);
    for(i=0; i<len; i++){
        sub[i] = s[startloc+i];
    }
    
    sub[i] = '\0';
}

int main(void){
    int len = 0;
    int startloc = 0;
    char s[100];
    
    printf("len: ");
    scanf("%d", &len);
    printf("startloc index:");
    scanf("%d", &startloc);
    printf("string :");
    scanf("%s", s);
    
    substr(s, startloc, len);
    
    printf("sub: %s", sub);
    
    return 0;
}
