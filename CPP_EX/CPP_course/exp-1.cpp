#include <iostream>
using namespace std;

template <class T>
T** AlloMemory(int m, int n){
    T** dm;
    
    dm = new T * [m];
    for(int i=0; i<m; i++){
        if((dm[i] = new T [n])==0){
            exit(0);
        }
    }
    
    cout << "Enter data: " << endl;
    
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
    
    cout << endl << "free successfully!" << endl;
    return 0;
}

template <class T>
void OutputMatrix(T** p, int m, int n){
	cout << endl << "Your result is: " << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void){
    int m = 0, n = 0;
    int **p;
    char **c;
    
    cout << "input matrix size, m, n: ";
    cin >> m >> n;
    cout << endl << "use of int " << endl;
    p = AlloMemory<int>(m, n);
    OutputMatrix(p, m, n);
    FreeMemory(m, n, p);
    
    cout << endl << "use of char " << endl;
    c = AlloMemory<char>(m, n);
    OutputMatrix(c, m, n);
    FreeMemory(m, n, c);
    
    return 0;
}
