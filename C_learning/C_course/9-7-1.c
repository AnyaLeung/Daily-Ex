#include <stdio.h>
#include <string.h>

int totsubstrnum(char *str, char *substr){
    int i = 0, j = 0, k = 0; 
    int lena = 0, lenb = 0;
    int count = 0;

    lena = strlen(str);
    lenb = strlen(substr);
    while(str[i]!='\0'){
        if(strncmp(str+i, substr, lenb)==0){
            count++;
            i += lenb;
        }
        else i++;
    }

    return count;
}

int main(void){
    char str[100], substr[100];
    printf("enter string: ");
    gets(str);
    printf("enter substring: ");
    gets(substr);

    
    printf("count :%d", totsubstrnum(str, substr));

    return 0;
}


