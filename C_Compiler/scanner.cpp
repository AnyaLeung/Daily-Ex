#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

/* global variables */
char input[100] = "";
int input_count = 0;

char s_word[100] = "";
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

bool IsLetter(){
    if(input[p_index]>='a'&&input[p_index]<='z'){
        return true;
    }

    if(input[p_index]>='A'&&input[p_index]<='Z'){
        return true;
    }
    return false;
}

bool IsDigit(){
    return (input[p_index]>='0' && input[p_index]<='9');
}

bool IsDelimiter(){
    return (input[input_count]==' ' || input[input_count]=='\0');
}

void BackSpace(int n){
    p_index -= n;
}

void SeperatePauseInput(void){
        WsIgnorance();
        while(!IsDelimiter()){
            s_word[s_count++] = input[input_count++];
            cout << "s_count: " << s_count << endl;
        }
        s_word[s_count++] = '#';
        WsIgnorance();
}

int main(void){
    cout << "Enter your program(end with #):";
    scanf("%[^#]s", input);
    cout << "input: " << input << endl;

    while(input[input_count]!='\0'){
        SeperatePauseInput(); //divide into words
        cout << "s_word: " << s_word << endl;
        cout << endl;
    }
    
    return 0;
}
