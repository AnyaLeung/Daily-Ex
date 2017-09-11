#include <iostream>
#include <string.h>
using namespace std;

class String{
    private:
        int len;
        char *p;
    public:
        String(char *g=NULL){
            *p = *g; 
            cout << "constructor" << *p << endl;
        }
        void ShowString(){
            cout << p;
        }
        int Length(){
           len = strlen(*p);
        }
        ~String(){
            cout << "destructor" << *p << endl;
        }
};

char s[5] = "abc";

int main(void){
    String s1 = String("12345");
    String s2 = String(s);
    return 0;
}
