#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std; 
/* global variables */
char input[255] = "";
int input_count = 0;

char s_word[255] = "";
int s_count = 0;
int p_start = 0;

char p_token[255] = "    abc 123 ab123 123ab  aaaaaa &&  ";
int p_index = 0;
/* global variables end */

class WORD{
    public:
        int typenum;
        string word_name;
};

void EmptyPtoken(void){
    for(int i=0; i<256; i++){
        p_token[i] = ' ';
    }
}
void strmncpy(int m, int n){
    EmptyPtoken();
    int count = 0;
    for(int i=m; i<n+1; i++){
        p_token[count++] = s_word[i];
    }
    p_token[count++] = '\0';
}

void WsIgnorance(){
    while(input[input_count]==' '|| input[input_count]==10){
        input_count++;
    }
}

bool IsDelimiter(){
    return (input[input_count]==' ' || input[input_count]=='\0');
}

void BackSpace(int n){
    p_index -= n;
}

void SeperatePauseInput(void){
        WsIgnorance();
        p_start = s_count;
        while(!IsDelimiter()){
            s_word[s_count++] = input[input_count++];
        }
        WsIgnorance();
}

bool IsLetter(){
    return ((p_token[p_index]>='a'&&p_token[p_index]<='z')
            || (p_token[p_index]>='A'&&p_token[p_index]<='Z'));
} //ok

bool IsDigit(){
    return (p_token[p_index]>='0' && p_token[p_index]<='9');
} //ok

bool IsID(void){
    int origin_pindex = p_index;
    char word[255];
    int count = 0;

    if(IsLetter()){
        word[count++] = p_token[p_index++];

        while(p_token[p_index]!='\0'){ //till the end
            if(IsLetter() || IsDigit()){
                word[count++] = p_token[p_index++];
            }
            else{ 
                p_index = origin_pindex;
                return false;
            }
        }
    }
    else{
        p_index = origin_pindex;
        return false;
    }
    p_index = 0;
    return true;
}

bool IsNum(){
    int origin_pindex = p_index;
    char num[255];
    int count = 0;

    if(IsDigit()){
        num[count++] = p_token[p_index++];
        cout << "num:" << " ";

        while(p_token[p_index]!='\0'){ //till the end if(IsDigit()){
            if(IsDigit()){
                num[count++] = p_token[p_index++];
            }
            else{
                p_index = origin_pindex;
                return false;
            }
        }
    }
    else{
        p_index = origin_pindex;
        return false;
    }

    return true;
}

void MatchToken(void){
    strmncpy(p_start, s_count-1); //load word to token buffer
    cout << "p_token:#" << p_token << '#' << endl;
    cout << "first_char: " << p_token[0] << endl;
    cout << "ID:" << IsID() << endl;
    cout << "NUM:" << IsNum() << endl;
    cout << endl;
}

int main(void){
    cout << "Enter your program(end with #):";
    scanf("%[^#]s", input);

    //cout << IsID("abc") << IsID("1abc") << IsID("123") << endl;

    while(input[input_count]!='\0'){
        SeperatePauseInput(); //divide into words
        MatchToken();
        //cout << "start: " << p_start << " " << "end: " << s_count-1 << endl;
        //cout << endl;
    }
    return 0;
}
