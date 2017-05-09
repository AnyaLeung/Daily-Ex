#include <stdio.h>
void Mycat(char dest[], char src[]){
    int i = 0, j = 0;
    while(dest[i]!='\0'){
        i++;
    }
    while(src[j]!='\0'){
        dest[i++] = src[j++];
    }
    dest[i] = '\0';
}

int main(void){
    char dest[80], src[80];
    printf("dest:");
    gets(dest);
    printf("src:");
    gets(src);

    Mycat(dest, src);
    puts(dest);
    return 0;
}
