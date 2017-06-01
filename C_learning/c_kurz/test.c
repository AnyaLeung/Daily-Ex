#include <stdio.h>


char Test(char a){
    if(a>='A'&&a<='Z'){
        a -= 'A';
        a += 'a';
        return a;
    }
    if(a>='a'&&a<='z') return a;
    else return 0;
}

int main(void){
    char a;
    a = Test(0);
    printf("%c", a);
    if (!a){
        count++;
    }
    return 0;
}
