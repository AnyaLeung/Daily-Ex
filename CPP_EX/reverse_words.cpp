#include <stdio.h>
#include <string.h>

int main(void) {
    char words[100] = "华中师大";
    int i = 0;

    strlen(words); //reverse string

    for (; words[i]; i++) {
        printf("%c%c", words[i+1], words[i]);
        i++;
    }

    return 0;
}
