#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
//keywords: begin, if, then, while, do, end
//oprators: = + - * / < <= <> > >= = ;
using namespace std;

/* global var */
char input[255] = "";
int token_no = 0; //amount o' tokens
char token_text[255];
int p_index; //present char index

//dict

/* global def */
class WORD{
    public:
        int typenum;
        string word_name;
};

/* single char process */
void WsIgnorance(){
    while(input[p_index]==' '|| input[p_index]==10)
        p_index++;
} //ok

bool IsLetter(){
    if(input[p_index]>='a'&&input[p_index]<='z'){
        return true;
    }

    if(input[p_index]>='A'&&input[p_index]<='Z'){
        return true;
    }
    return false;
} //ok

bool IsDigit(){
    if(input[p_index]>='0' && input[p_index]<='9'){
        return true;
    }

    return false;
}

bool IsEnding(){
    if(input[p_index]=='\0'){
        return true;
    }
    return false;
}

bool IsID(){
    char word[255];
    char *p = word;
    int count = 0;

    if(IsLetter()){
        word[count++] = input[p_index];
        p_index++;
        
        while(!IsEnding()){
            if(IsLetter() || IsDigit()){
                word[count++] = input[p_index];
                p_index++;
            }
            else{
                return false;
            }
        }
    }
    else{
        return false;
    }

    //cout << "word: " << word;
    strcmp(token_text, word); return true;
}

/*
   bool IsID(){
   char word[255];
    char *p
    int count = 0;
    bool flag = false;
    
    if(IsLetter()){
        word[count++] = input[p_index-1]; //save first char
        flag = true;
        while(!IsEnding() && flag){
            if(IsLetter() || IsDigit())
                word[count++] = input[p_index-1]; //save other words
            else flag = false; 
        }
    }
    else return false;

    if(flag){
        strcpy(token_text, word);
        cout << "token_text: " << token_text;
        return true;
    }
    else return false;
}
*/
/* single char process end */

void Scanner(){
    WsIgnorance();
    IsID();
}

void PrintRes(WORD w){
    cout << "(" << w.typenum << ", " << w.word_name << ")";
}

int main(void){
    cout << "Enter your program(end with #):";
    scanf("%[^#]s", input);
    Scanner();
}
