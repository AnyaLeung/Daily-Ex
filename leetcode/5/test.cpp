#include <iostream>
#include <string>

using namespace std;

/*
string LongestCommonString(string s1, s2){
    return S;
}
*/

string Reverse(string s){
    cout << "ok";
    cout << s << endl;
    string sr;
    int SLen = s.size();
    int count = SLen; 

    for(int i=0; i<SLen; i++){
        sr[i++] = s[count--];
    }

    cout << sr << endl;
    return sr;
}

/*
string longestPalindrome(string s) {

}
*/

int main(void){
    string a = ("abc");
    Reverse(a);
    //cout << Reverse(a) << endl;
    string b = ("a");
    Reverse(b);
    //cout << Reverse(b) << endl;
    return 0;
}
