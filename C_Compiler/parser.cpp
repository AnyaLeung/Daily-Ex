#include <iostream>
#include <string.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std; 

/*
 *  At first, use input array to save user's input, 
 *  then filter out all whitespaces, '\0', 
 *  and save the processed sentense into s_word array.
 *
 *  Then use s_word to generate each token,
 *  and match them with ID / NUMBER / KEYWORD / OPRATOR,
 *  and print the result.
 */

/* global variables */
map <string, int> Kwords = {
    {"main", 1}, {"int", 2}, {"char", 3}, {"if", 4}, 
    {"else", 5}, {"for", 6}, {"while", 7}
};

map <string, int> Ops = {
    {"=", 21}, {"+", 22}, {"-", 23}, {"*", 24}, 
    {"/", 25}, {"(", 26}, {")", 27}, {"[", 28}, {"]", 29}, {"{", 30}, {"}", 31}, {",", 32}, 
    {":", 33}, {";", 34}, {">", 35}, {"<", 36}, 
    {">=", 37}, {"<=", 38}, {"==", 39}, {"!=", 40},
};

vector <char> SingleOp = {
    '=', '+', '-', '*', '/', '(', ')', '[', ']', '{', '}', 
    ',', ':', ';', '>', '<', '!'
};

char input[255] = "";
int input_count = 0;
char s_word[255] = "";
int s_count = 0;
int p_start = 0;
char p_token[255] = "";
int p_index = 0;
int pcode = -1;
/* global variables end */

/* function prototype */
void EmptyPtoken(void); 
void strmncpy(int m, int n);
void WsIgnorance(void);
bool IsDelimiter(void);
bool Strcmp(map <string, int> M, char* S);
void SeperatePauseInput(void);
bool IsLetter(void);
bool IsDigit(void);
bool IsKword(void);
bool IsOps(void);
bool IsID(void);
bool IsNum(void);
void MatchToken(void);
bool One_parser(void);
bool Two_parser(void);
void GetNextToken(void);
//bool IsEnd(void);
bool StatementSequence(void);
bool Statement(void);
bool AssignValueState(void);
bool ConditionState(void);
bool LoopState(void);
bool Expression(void);
bool Term(void);
/* function prototype end */

/* main func */
int main(void){
    cout << "Enter your program(end with #):";
    scanf("%[^#]s", input);

    One_parser();

    return 0;
}
/* main func end */

/* func declaration */ void EmptyPtoken(void){
    for(int i=0; i<256; i++){
        p_token[i] = ' ';
    }
}

/*
bool IsEnd(void){
    //cout << "p_token: " << p_token[p_index] << endl;
    return (p_token[p_index+1]=='\0');
}
*/

void strmncpy(int m, int n){
    EmptyPtoken();
    int count = 0;
    for(int i=m; i<n+1; i++){
        p_token[count++] = s_word[i];
    }
    p_token[count++] = '\0';
}

void WsIgnorance(void){
    while(input[input_count]==' '|| input[input_count]==10){
        input_count++;
    }
}

bool IsDelimiter(void){
    return (input[input_count]==' ' || input[input_count]=='\0' 
            || input[input_count]=='\n');
}

bool Strcmp(map <string, int> M, char* S){
    string p_str(S);

    auto search = M.find(p_str);
    if(search!=M.end()){
        cout << "(" << search->second << ", " << search->first << ") ";
        pcode = search->second; //for parsing
        return true;
    }
    else{
        return false;
    }
    return true;
}

void SeperatePauseInput(void){
    WsIgnorance();
    p_start = s_count;

    while(!IsDelimiter()){
        char p_op[2] = "";
        if(find(SingleOp.begin(), SingleOp.end(), input[input_count])!=SingleOp.end()){ //present is ops
            p_op[0] = input[input_count];
            p_op[1] = input[input_count+1];
            s_word[s_count++] = input[input_count++];

            if((p_op[0]=='>'||p_op[0]=='<'||p_op[0]=='='||p_op[0]=='!')&&
                    p_op[1]=='='){
                s_word[s_count++] = input[input_count++];
                return ;
            }
            else {
                return ;
            }
        }

        if(find(SingleOp.begin(), SingleOp.end(), input[input_count+1])!=SingleOp.end()){ //next is 
            s_word[s_count++] = input[input_count++];
            return ;
        }
        s_word[s_count++] = input[input_count++];
    }
    WsIgnorance();
}

bool IsLetter(void){
    return ((p_token[p_index]>='a'&&p_token[p_index]<='z')
            || (p_token[p_index]>='A'&&p_token[p_index]<='Z'));
} 

bool IsDigit(void){
    return (p_token[p_index]>='0' && p_token[p_index]<='9');
}

bool IsKword(void){
    if(Strcmp(Kwords, p_token)){ //retrieve all keys and compare with p_token
        p_index = 0;
        return true;
    }
    p_index = 0;
    return false;
}

bool IsOps(void){
    if(Strcmp(Ops, p_token)){ //retrieve all keys and compare with p_token
        p_index = 0;
        return true;
    }
    p_index = 0;
    return false;
}

bool IsID(void){
    char word[255];
    int count = 0;

    if(IsLetter()){
        word[count++] = p_token[p_index++];

        while(p_token[p_index]!='\0'){ //till the end
            if(IsLetter() || IsDigit()){
                word[count++] = p_token[p_index++];
            }
            else{ 
                p_index = 0; return false;
            }
        }
    }
    else{
        p_index = 0;
        return false;
    }
    p_index = 0;
    return true;
}

bool IsNum(void){
    char num[255];
    int count = 0;

    if(IsDigit()){
        num[count++] = p_token[p_index++];

        while(p_token[p_index]!='\0'){ //till the end if(IsDigit()){
            if(IsDigit()){
                num[count++] = p_token[p_index++];
            }
            else{
                p_index = 0;
                return false;
            }
        }
    }
    else{
        p_index = 0;
        return false;
    }
    p_index = 0;
    return true; 
}

bool One_parser(void){
    GetNextToken();
    if(pcode==1){ //starting token is "main"
        GetNextToken();
        if(pcode==26){ //next token is '('
            GetNextToken();
            if(pcode==27){ //next token is ')'
                if(Two_parser()){
                    cout << endl << "right" << endl;
                    return true;
                } 
                else{
                    cout << "error" << endl;
                    return false;
                }
            }
            else{
                cout << "error" << endl;;
                return false;
            }
        }       
        else{
            cout << "error" << endl;
            return false;
        }
    }
    else{
        cout << "error" << endl;
        return false;
    }
    return false;
} //ok

bool Two_parser(void){
   GetNextToken();
   if(pcode==30){ // next token is '{'
       GetNextToken();
       if(StatementSequence()){ //statement sequence is true
           return true;
       }
       else{
           cout << "error" << endl;
           return false;
       }
   }
   else{
       cout << "error" << endl;
       return false;
   }
   return false;
} //ok

bool StatementSequence(void){
    if(Statement()){ //first token is statement
        GetNextToken();
        if(pcode==34){ //token is ';'
            GetNextToken();
            if(pcode==31){ // is '}'
                GetNextToken();
                if(pcode==-1){
                    return true;
                }
                else{
                    cout << "error8" << endl;
                    return false;
                }
            } //finish parsing with ID and assign statement
            if(Statement()){
                GetNextToken();
                if(pcode==34){ //token is ';'
                    GetNextToken();
                    if(pcode==31){ //token is '}'
                        GetNextToken();
                        if(pcode==-1){
                            return true;
                        }
                        else{
                            cout << "error2" << endl;
                            return false;
                        }
                    }
                    else{
                        cout << "error3" << endl;
                        return false;
                    }
                }

                else{
                    cout << "pwrong:" << p_token << endl;
                    cout << "error4" << endl;
                    return false;
                }
            }
            else{
                cout << "error5" << endl;
                return false;
            }
        }
        else{
            cout << "error6" << endl;
            return false;
        }
    }
    else{ 
        cout << "error7" << endl;
        return false;
    }
    return false;
}

bool Statement(void){
    if(AssignValueState()){
        //cout << "ok1" << endl;
        return true;
    } 
    /*
    if(ConditionState()){
        return true;
    }
    if(LoopState()){
        return true;
    }
    */
    return false;
}

bool AssignValueState(void){
    cout << "p2:" << p_token << endl;
    if(pcode==10){ //token is ID
        GetNextToken();
        cout << "p3:" << p_token << endl;
        if(pcode==21){ //token is '='
            if(Expression()){
                return true;
            }
            else{
                cout << "error 16 " << endl;
                return false;
            }
        }
        else{
            cout << "error 15" << endl;
            return false;
        }
    }
    else{
        cout << "error 10" << endl;
        return false;
    }
    return false;
}

bool Expression(void){
    cout << "p4:" << p_token << endl;
    if(Term()){
        GetNextToken();
        cout << "p4:" << p_token << endl;
        if(pcode==22 || pcode==23){ //token is '+' or '-'
            if(Term()){
                return true;
            }
        }
    }
    else{
        cout << "error11" << endl;
        return false;
    }
    return false;
}

bool Term(void){
    GetNextToken();
    cout << "p5:" << p_token << endl;
    if(pcode==10){
        return true;
    }
    return false;
}

bool ConditionState(void){
    GetNextToken();
    if(pcode==4){ //token is IF kword
            ;        
    }
    else{
        cout << "error1" << endl;
    }
    return true;
}

bool LoopState(){
    return true;
}

void GetNextToken(){
    pcode = -1;
    SeperatePauseInput();
    MatchToken();
}

void MatchToken(void){
    strmncpy(p_start, s_count-1);
    if(IsKword()){
        return ;
    }
    if(IsOps()){
        return ;
    }
    if(IsID()){
        cout << "(10, \"" << p_token << "\") ";
        pcode = 10;
        return ; 
    }
    if(IsNum()){
        cout << "(20, " << p_token << ") ";
        pcode = 20;
        return ;
    }
    if(p_token[p_index]=='\0'){
        return ;
    }
    cout << "(-1, ERROR!) ";
}
/* function declaration end*/
