#include <iostream>

using namespace std;

class Circle{
    private:
        char id;
        int radius;
        char *words;
    public:
        friend class CPPage; 
        static int countc;
        Circle(int radius){
            id = '1';
            countc++;
            cout <<"I'm a circle of radius" << radius << endl;

        }
        Circle(char a){
            id = a;
            countc++;
            cout << "hi, I'm circle  " << id << endl;
        }
        Circle(){
            countc++;
            id = '\0';
            cout << "constructor failed" << endl;
        }
        ~Circle(){
            cout << "destructor circle " << id << endl;
        }

        void ReadInfo(){
            words = new char[2*radius-4] + 1;
            cin >> words;
            cout << words;
        }

        void Show(){
            cout << "radius: " << radius << endl;
            cout << words << endl;

        }
        Circle(Circle &p){
            cout << "copy constructor, before call" << endl;
            radius = p.radius;
        }
};

int Circle::countc = 0;
