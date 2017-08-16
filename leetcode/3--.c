#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    char *p;
    int count = 0;
    int record[27] = {0};

    p = s;
    while(*p!='\0'&& record[*p-'a']==0){
        printf("%c", *p);
        record[*p-'a'] ++;
        p++;
        count++;
    }
    return count;
}

int main(void){
    char s[10] = "abcabc\0";
    int a = 0;
    a =  lengthOfLongestSubstring(s);
    printf("a: %d\n", a);

    return 0;
}
