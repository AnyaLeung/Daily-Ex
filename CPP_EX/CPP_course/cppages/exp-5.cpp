#include <iostream>
using namespace std;
/*
 * 设计CGraph, 设计属性成员，type（用数字表示
 * color线条颜色，linewidth等
 * 设计成员函数：show，用于显示定义的属性值
 *
 * 修改实验中的CRect和CCircle类，使其共有继承自CGraph,
 * 注意修改构造函数
 *
 * 设计圆角矩形类，CCircleRect,使其继承自CCircle和CCircle，定义相关的show函数，并在cppage类加入该类的组合成员
 */

class CGraph{
   private:
   int type;
   int color;
   int linewidth;

   public:
   CGraph(int t=0, int c=0, int lw=0){
        this->type = t;
        this->color = c;
        this->linewidth = lw;
   }

   void ShowInfo(){
       cout << "type: " << type << endl;
       cout << "color: " << color << endl;
       cout << "linewidth: " << linewidth << endl;
   }
};

class Rectangle:  virtual public CGraph{
    private:
        char id;
        int width, height;
        char *words;

    public:
        Rectangle(int l=0, int h=0, int t=1, int c=0, int lw=0): CGraph(t, c, lw){
            width = l;
            height = h;
            id = '1';
            cout << "I'm a rec of height " << height << " and width " << width << endl;
        } //构造函数

        void ReadInfo(){
            words = new char[width-4] + 1;
            do{
                cout << "enter your info for the rect, less than " << width - 4 << " words" << endl;
                cin >> words;
            } while(strlen(words)>width);
        } //录入信息

        void Show(){
            cout << "height: " << height << endl;
            cout << "width: " << width << endl;
            cout << "my info" << words << endl;
        } //读取信息
};

class Circle : virtual public CGraph{
    private:
        char id;
        int radius;
        char *words;

    public:
        Circle(int r, int t=2, int c=0, int lw=0): CGraph(t, c, lw){
            id = '1';
            radius = r;
            cout <<"I'm a circle of radius " << radius << endl;
        }

        void ReadInfo(){
            words = new char[radius] + 1;
            cin >> words;
            cout << words;
        }

        void Show(){
            cout << "radius: " << radius << endl;
            cout << words << endl;

        }
};

class CCircleRect : public Circle, public Rectangle{
    public:
        CCircleRect(int r=0, int l=0, int h=0, int t=0, int c=0, int lw=0) : CGraph(t, c, lw), Rectangle(l, h), Circle(r){
            cout << "constructed ccirclerect" << endl;
        }

    void Show(){
        cout << "CCircleRect: " << endl;
        CGraph::ShowInfo();
        Rectangle::Show();
        Circle::Show();
    }
};

int main(void){
    Rectangle rect1(7, 8, 3, 4, 5);
    rect1.ShowInfo();
    rect1.ReadInfo();
    rect1.Show();

    Circle cir1(1, 2, 3, 4);
    cir1.ShowInfo();
    cir1.ReadInfo();
    cir1.Show();

    CCircleRect ccr1(10, 7, 8, 3, 0, 1);
    ccr1.Rectangle::ReadInfo();
    ccr1.Circle::ReadInfo();
    ccr1.Show();

    return 0;
}
