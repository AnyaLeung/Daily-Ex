#include <string.h>
#include <stdio.h>

int strStr(char* haystack, char* needle) {
    int len = strlen(haystack);
    int len_needle = strlen(needle);

    if (!len && !len_needle) return 0;

    int i = 0;
    for(i=0; i<len; i++){
        if(!strncmp(haystack+i, needle, len_needle)){
            return i;
        }
    }
    return -1;
}

