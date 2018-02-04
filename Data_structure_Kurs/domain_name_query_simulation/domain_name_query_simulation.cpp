#include <iostream>
#include <unistd.h>
#include <stack>
#include <string>

using namespace std;

stack<string> SplitSpaceOrDot(char* enter, int len);
stack<string> ReadSite();

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* Tree;

struct TreeNode{
    char* Name;
    Position Child;
    Position Sibling;
}; //name , child, sibling

void NotFound(string site){
    cout << "This site can’t be reached." << endl;
    cout << site << "'s server DNS address could not be found." << endl;
    cout << endl;
    cout << "site: " << site << endl;;
}

stack<string> ReadSite(){
        stack<string> enter;
        stack<string> s;

        cout << "Welcome, you can enter site here, we'll map it into domain name: " << endl;
        cin >> enter;

        s = SplitSpaceOrDot(enter);
        return s;
}

stack<string> SplitSpaceOrDot(stack<string> enter){
    char* p, *q;
    string str[4];
    stack<string> str_sta;
    int count = 0;
    int len = enter.size();

    p = &enter[0];
    q = &enter[len-1];
    while(*q!='\0') {
        while (*q != '.') {
            str[count] += *q;
        }
        str_sta.push(str[count]);
        count ++;
    }
    return str_sta;
} //push like "www" "baidu" "com" into stack, reversely

void ReadAll(stack<string> s){
    while(s.size()){
        cout << s.top() << "   ";
        s.pop();
    }
}

int main(void){
    stack<string> s;
    s = ReadSite();
    ReadAll(s);

    //system("open http://www.baidu.com");
    return 0;
}
