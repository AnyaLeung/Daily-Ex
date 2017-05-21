#include <stdio.h>
#include <string.h>

void fun(char input[], char new[]){
    int len = 0;
    int j = 0;
    len = strlen(input);
    for(int i=0; i<len; i++){
        if(input[i]>'9'|| input[i]<'0'){
            new[j++] = input[i];
        }
    }
}

int main(void){
    char input[100];
    char new[100];
    scanf("%s", input);
    
    fun(input, new);
    printf("%s", new);
    return 0;
}
