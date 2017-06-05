#include <stdio.h>

int main(void){
    char str[100];
    int i = 0, j = 0;
    int num[26] = {0};

    scanf("%s", str);
    for(i=0; i<100; i++){
        if(str[i]>='a'&&str[i]<='z'){
            num[str[i]-'a']++;
        }
    }
    
    for(j=0; j<26; j++){
        if(num[j]){
            printf("%c: %d\n", (char)(j+'a'), num[j]);
        }
    }

    return 0;
}
