#include <iostream>
/*
 * 组合对象的使用，
 * 设计类似ppt的类CPPage, 包含一个矩形对象数组和一个圆形对象数组，
 * 矩形类为实验三中的类
 *
 * 增加一个静态成员对矩形类计数，圆形类仿照矩形类设计
 *
 * 设计成员函数Show显示本ppt页的相关信息：矩形个数，圆形个数
 *设置CPPage类为矩形类的友元类，并在show函数中直接访问矩形类的字符串
 *
 * 对象信息的输入采取读取文本文件的方式（*）
 */

using namespace std;

class Rectangle{
    private:
        char id;
        int length, height;
        char *words;
    public:
     //   friend class CPPage;
        static int countR;
        Rectangle(int l=0, int h=0){
            length = l;
            height = h;
            countR++;
            id = '1';
          //  cout << "I'm a rec of height " << height << "and length " << length << endl;

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
            countR++;
        }
        friend  class CPPage;
};

class Circle{
    private:
        char id;
        int radius;
        char *words;
    public:
    //    friend class CPPage;
        static int countC;
        Circle(int radius=5){
            id = '1';
            this->radius = radius;
            countC++;
         //   cout <<"I'm a circle of radius" << radius << endl;

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
            countC++;
        }
        friend  class CPPage;
};

class CPPage{
    private:
        Circle *ci;
        Rectangle *re;
        int id;
    public:
        CPPage(int id=0){
            id = id;
            re = new Rectangle[2];
            ci = new Circle[2];
        }

        void getinput(){
            int i = 0;
            int l = 0, h = 0, r = 0;
            char *p;
            cout << "input" << endl;
            for(int i=0; i<2; i++){
                cout << "width and height: " << endl;
                cin >> l >> h;
                re[i] = Rectangle(l, h);
                re[i].words = new char[100];
            }

            for(int j=0; j<2; j++){
                cout << "enter radius: " << endl;
                cin >> r;
                ci[j] = Circle(r);
            }

            for(int k=0; k<2; k++){
                cout << "enter words: " << endl;
                cin >> re[k].words;
            }
            cout << "completed read rect and cir" << endl;
        }

        void Show(){
            cout << "total " << Rectangle::countR << " rectangle" << endl;
            cout << "total " << Circle::countC << " circle" << endl;
            cout << "info for rect 1" << re[0].words << endl;
            cout << "info for rect 2" << re[1].words << endl;
        }

        friend class Rectangle;
        friend class Circle;
};

int Rectangle::countR = 0;
int Circle::countC = 0;

int main(void){
    CPPage page1(1);
    page1.getinput();
    page1.Show();

    return 0;
}
