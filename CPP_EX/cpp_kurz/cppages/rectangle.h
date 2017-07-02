#include <iostream>
#include <string.h>
//#include "CPPage.h"

using namespace std;

class Rectangle{
    private:
        char id;
        int length, height;
        char *words;
    public:
        friend class CPPage;
        static int countr;
        Rectangle(int l=0, int h=0){
            length = l;
            height = h;
            countr++;
            id = '1';
            cout << "I'm a rec of height " << height << "and length " << length << endl;

        }
        Rectangle(char a){
            id = a;
            countr++;
            cout << "hi, I'm rec  " << id << endl;
        }
        Rectangle(){
            length = 0;
            height = 0;
            countr++;
            id = '\0';
            cout << "constructor failed" << endl;
        }
        ~Rectangle(){
            cout << "destructor Rec " << id << endl;
        }

        void DrawRec(){
            for(int i=0; i<height; i++){
                for(int j=0; j<length; j++){
                    if(i==0||i==height-1) {
                        cout << "*";
                    }
                    else{
                        if(j==0||j==length-1){
                            cout << "*";
                        }
                        else{
                            cout << " ";
                        }
                    }
                }
                    cout << endl;
            }
        }

        void ReadInfo(){
          words = new char[length-4] + 1;
          cin >> words;
          cout << words;
        }
        void Show(){
            cout << "height: " << height << endl;
            cout << "length: " << length << endl;
            cout << "my info" << words << endl;

        }
        Rectangle(Rectangle &p){
            cout << "copy constructor, before call" << endl;
            height = p.height;
            length = p.length;
        }
};

int Rectangle::countr = 0;
