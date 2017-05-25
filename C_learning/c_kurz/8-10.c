#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str;

void alter(int no);

int main(void){
    int no = 0;

    printf("enter number: ");
    scanf("%d", &no);

    alter(no);
    printf("string: %s", str);
    return 0;
}

void alter(int no){
    int i = 0;
    int put = 0;
    
    str = (char *)malloc(no * sizeof(char));

    if(no==0) ;
    else{
        put = no % 10;
        for(i=strlen(str); i>=0; i--){
            strcpy(str+1, str);
        }
        *str = (char)put - 48;
        alter( no / 10);
    }
}
