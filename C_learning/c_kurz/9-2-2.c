#include <stdio.h>

void mycat(char *dest, char *src){
    int i = 0, j = 0;
    while(dest[i]!='\0'){
        i++;
    }

    while(src[j]!='\0'){
        dest[i++] = src[j++];
    }

    dest[j] = '\0';
}

int main(void){
    char dest[100], src[100];

    scanf("%s", dest); //gets(dest);
    scanf("%s", src);

    mycat(dest, src);
    printf("after cat: %s", dest);

    return 0;
}
