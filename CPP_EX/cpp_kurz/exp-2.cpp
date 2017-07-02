#include <iostream>
using namespace std;

class Clock{
    private:
        int H, M, S;
    public:
        Clock(int h=0, int m=0, int s=0){
            H = h;
            M = m;
            S = s;
            cout << "constructor" << H << ":" << M << ":" << S;
        }

        Clock(char a){
            cout << "constructor default" << endl;
        }

        ~Clock(){
            cout << "destructor" << endl;
        }


};

int main(void){
    Clock newclock = Clock('a');
    return 0;
}
