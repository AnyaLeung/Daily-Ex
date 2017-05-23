#include <stdio.h>
#include <string.h>

char sub[100];

void substr(char *s, int startloc, int len){
    int i = startloc;
    int j = 0;
    char temp;
    

    for(; i<i+len; i++){
        temp = *s;
        sub[j] = temp;
        j++;
        s++;
    }

    sub[j] = '\0';
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
