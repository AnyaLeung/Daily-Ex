#include <iostream>

using namespace std;

int CalFac(int num);
bool Judge(int n);

int main(void){
    int no = 0, res = 0;

    cin >> no;
    if(Judge(no)){
        res = CalFac(no);
        cout << "阶乘结果为: " << res;
    }
    return 0;
}

int CalFac(int num){
    if(num==1){
        return num;
    }
    else{
        num *= CalFac(num-1);
    }
    return num;
}

bool Judge(int n){
    if(n>16){
        cout << "溢出前n为16" << endl;
        cout << "此时的阶乘结果为: 2004189184";
        return 0;
    }
    else{
        return 1;
    }
}
