/*
 * FUCK TEXTBOOK, 
 * FUCK ALL CODES IN THIS BOOK
 */

#include <iostream>
#include <string.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std; 

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
int p_p_start = 0;
int p_s_count = 0;
int p_input_count = 0;
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
bool StatementSequence(void);
bool Statement(void);
bool AssignValueState(void);
bool ConditionState(void);
bool LoopState(void);
bool Expression(int npcode);
bool Term(int npcode);
bool Factor(void);
void Back2PreviousToken(void);
bool Condition(void);
/* function prototype end */

/* main func */
int main(void){
    cout << "Enter your program(end with #):";
    scanf("%[^#]s", input);

    One_parser();

    return 0;
}
/* main func end */

/* func declaration */ 
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

    p_p_start = p_start;
    p_s_count = s_count;
    p_input_count = input_count;

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
    if(pcode==1){ // is "main" kword
        GetNextToken();
        if(pcode==26){ // is '('
            GetNextToken();
            if(pcode==27){ // is ')'
                if(Two_parser()){
                    cout << "ok in parser one" << endl;
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
}

bool Two_parser(void){
   GetNextToken();
   if(pcode==30){ //is '{'
       if(StatementSequence()){ //statement sequence is true
           GetNextToken();
           if(pcode==31){ // is '}'
               cout << "ok in Two_parser" << endl;
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
   }
   else{
       cout << "error" << endl;
       return false;
   }
   return false;
} //ok

bool StatementSequence(void){
    if(Statement()){ 
        GetNextToken();
        Back2PreviousToken();
        if(pcode==31){ // is '}'
            cout << "ok in statesequence and finish 1 sta" << endl;
            return true;
        } 
        if(Statement()){
            GetNextToken();
            if(pcode==31){ // is '}'
                Back2PreviousToken();
                cout << "ok in statesequence and finish 2sta" << endl;
                return true;
            }
            else{
                cout << "error 43" << endl;
                return false;
            }
        }
        else{
            cout << "error 42" << endl;
            return false;
        }
    }
    else{
        cout << "error 41" << endl;
        return false;
    }
    return false;
}

bool Statement(void){
    GetNextToken();
    if(pcode==10){ //ID
        Back2PreviousToken();
        if(AssignValueState()){
            return true;
        }
        else{
            cout << "error 100" << endl;
            return false;
        }
    }
    if(pcode==4){
        Back2PreviousToken();
        if(ConditionState()){
            return true;
        }
        else{
            cout << "error 101" << endl;
            return false;
        }
    }
    /*
    if(pcode==7){
        Back2PreviousToken();
        if()
    }
    else
    }
    */
    return false;
}

bool AssignValueState(void){
    GetNextToken();
    if(pcode==10){ //token is ID
        GetNextToken();
        if(pcode==21){ //token is '='
            cout << "p3:" << p_token << " ";
            if(Expression(34)){ // end with ;
                GetNextToken();
                if(pcode==34){ //is ;
                    cout << "Right parsing." << endl;
                    return true;
                }
                else{
                    cout << "error 15.5" << endl;
                    return false;
                }
                cout << "ok1" << endl;
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

bool Expression(int npcode){
    if(Term(npcode)){
        GetNextToken();
        cout << "p4:" << p_token << " ";
        if(pcode==22 || pcode==23){ //token is '+' or '-'
            cout << "ok6" << endl;
            if(Term(npcode)){
                cout << "ok7" << endl;
                return true;
            }
        }
        if(pcode==npcode){ //is end
            Back2PreviousToken();
            return true;
        }
        else{
            cout << "error 30" << endl;
            return false;
        }
    }
    else{
        cout << "error11" << endl;
        return false;
    }
    cout << "error 11" << endl;
    return false;
}

//npcode==34 ;
bool Term(int npcode){
    if(Factor()){
        GetNextToken();
        cout << "p5:" << p_token << " ";
        if(pcode==npcode){ //is ';'
            Back2PreviousToken();
            cout << "ok3" << endl;
            return true;
        }
        if(pcode==22 | pcode==23){ //token is '+' or '-'
            Back2PreviousToken();
            cout << "ok2" << endl;
            return true;
        }
        if(pcode==24 || pcode==25){ //token is '*' or '/'
            if(Factor()){
                cout << "ok333" << endl;
                return true;
            }
            else{
                cout << "error 19" << endl;
                return false;
            }
        }
        else{
            cout << "error 18 " << endl;
            return false;
        }
    }
    else{
        cout << "error 17" << endl;
        return false;
    }
    return false;
}

bool Factor(void){
    GetNextToken();
    if(pcode==10 || pcode==20){ //ID or num 
        //cout << "p7:" << p_token << endl;
        return true; 
    }
    if(Expression(34)){ //end with ;
        return true;
    }
    else{
        cout << "factory error" << endl;
        return false;
    }
    return false;
}

bool ConditionState(void){
    GetNextToken();
    if(pcode==4){ //is IF kword
        GetNextToken();
        if(pcode==26){ //is '('
            if(Condition()){
                GetNextToken();
                if(pcode==27){ //is ')'
                   if(Two_parser()){
                       return true;
                   }
                   else{
                       cout << "error 53" << endl;
                       return false;
                   }
                }
                else{
                    cout << "error 52" << endl;
                    return false;
                }
            }
            else{
                cout << "error 51" << endl;
                return false;
            }
        }
        else{
            cout << "error 50" << endl;
            return false;
        }
    }
    else{
        cout << "error1" << endl;
    }
    return true;
}

bool Condition(void){
    if(Expression(35) || Expression(36) || Expression(37)
        || Expression(38) || Expression(39) || Expression(40)){ 
        //end with logical ops)
        GetNextToken();
        if(pcode>34 && pcode<41){ // is '>''<''>=''<=''==''!='
            if(Expression(27)){ //end with )
                cout << "okok" << endl;
                return true;
            }
            else{
                cout << "error 56" << endl;
                return false;
            }
        }
        else{
            cout << "error 55" << endl;
            return false;
        }
    }
    return false;
}

bool LoopState(){
    return true;
}

void GetNextToken(){
    pcode = -1;
    SeperatePauseInput();
    MatchToken();
}

void Back2PreviousToken(void){
    p_start = p_p_start;
    s_count = p_s_count;
    input_count = p_input_count;
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
