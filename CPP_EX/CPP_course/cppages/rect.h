#include <iostream>
#include <string.h>
using namespace std;

class Rectangle{
    private:
        char id;
        int width, height;
        char *words;
    public:
        Rectangle(int l=0, int h=0){
            width = l;
            height = h;
            id = '1';
            cout << "I'm a rec of height " << height << " and width " << width << endl;

        } //构造函数1
        Rectangle(char a){
            id = a;
            cout << "hi, I'm rec " << id << endl;
        } //构造函数2

        ~Rectangle(){
            cout << endl << "destructor Rec " << id << endl;
        } //析构函数

        Rectangle(Rectangle & p, int i){
            bool choose = 1;
            choose = i;
            if(!choose){
                cout << "shallow copy constructor, before call" << endl;
                height = p.height;
                width = p.width;
                id = p.id;
                strcpy(words, p.words);
            }

            if(choose){
                int len = strlen(p.words);
                cout << "deep copy constructor, before call" << endl;
                id = p.id;
                width = p.width;
                height = p.height;
                if(len!=0){
                    words = new char[len+1];
                    strcpy(words, p.words);
                }
            }
        } //浅拷贝构造函数

        void DrawRec(){
            for(int i=0; i<height; i++){
                for(int j=0; j<width; j++){
                    if(i==0||i==height-1) {
                        cout << "*";
                    }
                    else{
                        if(j==0||j==width-1){
                            cout << "*";
                        }
                        else{
                            cout << " ";
                        }
                    }
                }
                cout << endl;
            }
        } //方法一：画矩形

        void ReadInfo(){
            words = new char[width-4] + 1;
            do{
                cout << "enter your info for the rect, less than " << width << " words" << endl;
                cin >> words;
            } while(strlen(words)>width);

        } //方法二：录入信息

        void Show(){
            cout << "height: " << height << endl;
            cout << "width: " << width << endl;
            cout << "my info" << words << endl;
        } //方法三：读取信息 
};

