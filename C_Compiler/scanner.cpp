#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

/* global variables */
char input[100] = "";
int input_count = 0;

char s_word[10] = "";
int s_count = 0;

int p_index = 0;


/* global variables end */

class WORD{
    public:
        int typenum;
        string word_name;
};


void WsIgnorance(){
    while(input[input_count]==' '|| input[input_count]==10){
        input_count++;
    }
}

bool IsDelimiter(){
    return (input[input_count]==' ' || input[input_count]=='\0');
}

void SeperatePauseInput(void){
    if(IsDelimiter() || input_count==0){
        int n = 0;
        WsIgnorance();
        while(!IsDelimiter()){
            s_word[s_count++] = input[input_count++];
        }
    }
}


int main(void){
    cout << "Enter your program(end with #):";
    scanf("%[^#]s", input);

    SeperatePauseInput();
    
    return 0;
}
