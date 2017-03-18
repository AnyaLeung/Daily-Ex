#include <iostream>

using namespace std;

int fib(int n);

int main(void) {
    int n;
    cin >> n;
    cout << "fib("  << n << ")" << " is " << fib(n-1) << endl;
    return 0;
}

int fib(int n) {
    if (n<3)
        return n;
    else
        return fib(n-1)+fib(n-2);
}
