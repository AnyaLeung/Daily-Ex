#include <iostream>

using namespace std;

int Fact(int n);

int main(void){
    int no = 0;
    int res = 0;

    cin >> no;
    res = Fact(no);

    if(res){
        cout << "Result is: " << res << endl;
    }

    return 0;
}

int Fact(int n){
    int res = 1;
    if(n>12){
        cout << "Result overflow! While n is 12, result is 479001600." << endl;
        return 0;
    }

    if(n==1) ;
    else{
        n *= Fact(n-1);
    }

    return n;
}
