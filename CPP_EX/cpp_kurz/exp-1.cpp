#include <iostream>

using namespace std;

template <class T>
T** AlloMemory(int m, int n){
    T** dm;

    dm = new T * [m];
    for(int i=0; i<m; i++){
        if((dm[i] = new int [n])==0){
            exit(0);
        }
    }

    for(int j=0; j<m; j++){
        for(int s=0; s<n; s++){
            cin >> dm[j][s];
        }
    }

    return dm;
}

template <class T>
int FreeMemory(int m, int n, T** dm){
    for(int i=0; i<m; i++){
        delete[]dm[i];
    }
    delete[]dm;

    return 0;
}

int main(void){
    int m = 0, n = 0;
    cin >> m >> n;
    AlloMemory<int>(m, n);
    return 0;
}
