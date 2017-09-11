#include <iostream>
using namespace std;

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
