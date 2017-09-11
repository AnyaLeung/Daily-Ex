#include <iostream>
using namespace std;
/*
 * 将实验五的CGraph改为抽象类，（设计纯虚函数ShowMsg)。
 *
 * 修改实验五重的CRect, CCircle类，设计函数ShowMsg显示其所有信息。
 *
 * 修改CPPage类，原来的组合成员的类型改为CGraph*,并使用虚函数的方式，通过调用虚函数的方式，通过调用CGraph的指针调用ShowMsg，显示每个对象的信息 (...)
 *
 */

class CGraph{
    public:
        virtual void ShowMsg()=0;
        virtual void ReadInfo(){};
        virtual ~CGraph(){};
};

class Rectangle: virtual public CGraph{
    private:
        char id;
        int width, height;
        char *words;
        int type1, color1, linewidth1;

    public:
        Rectangle(int l=0, int h=0, int type=1, int color=0, int linewidth=0){
            width = l;
            height = h;
            id = '1';
            type1 = type;
            color1 = color;
            linewidth1 = linewidth;
            cout << "I'm a rec of height " << height << " and width " << width << endl;
        } //构造函数

        void ReadInfo(){
            words = new char[width-4] + 1;
            do{
                cout << "enter your info for the rect, less than " << width - 4 << " words" << endl;
                cin >> words;
            } while(strlen(words)>width);
        } //录入信息

        void ShowMsg(){
            cout << "height: " << height << endl;
            cout << "width: " << width << endl;
            cout << "my info" << words << endl;
            cout << "type, color, linewidth: " << type1 << color1 << linewidth1 << endl;
        } //读取信息
        ~Rectangle(){
        }
        friend class CPPage;
        friend class CircleRect;
};

class Circle: virtual public CGraph{
    private:
        char id;
        int radius;
        char *words;
        int type, color, linewidth;

    public:
        Circle(int r=5, int type=2, int color=0, int linewidth=0){
            id = '1';
            radius = r;
            cout <<"I'm a circle of radius " << radius << endl;
            type = type;
            color = color;
            linewidth = linewidth;
        }

        void ReadInfo(){
            words = new char[radius] + 1;
            cin >> words;
            cout << words;
        }

        void ShowMsg(){
            cout << "radius: " << radius << endl;
            cout << words << endl;        
            cout << "type, color, linewidth: " << type << color << linewidth << endl;
        }

        ~Circle(){
        }

        friend class CPPage;
        friend class CircleRect;
};


class CircleRect: public Circle, public Rectangle{
    private:
        char *words;
    public:
            CircleRect(int l=0, int h=0, int type1=3, int color1=0, int linewidth1=0, int r=0, int type=3, int color=0, int linewidth=0): Rectangle(l, h, type1, color1, linewidth1), Circle(r, type, color, linewidth){} ;

        void ShowMsg(){
            cout << "CircleRect: " << endl;
            Rectangle::ShowMsg();
            Circle::ShowMsg();
        }

        void ReadInfo(){
            words = new char[radius] + 1;
            cin >> words;
            cout << words;
        }
        friend class CPPage;
   };

class CPPage{
    public:
        int rno;
        int cno;
        int crno;
        CGraph *g[100];
        CPPage(int rno = 0, int cno = 0, int crno = 0){
            this->rno = rno;
            this->cno = cno;
            this->crno = crno;
        }

        void GetInput(){
            int r = 0, h = 0, l = 0;
            int i = 0;
            int j = 0;
            int k = 0;
            int type=0, color=0, linewidth=0;
            int type1 = 0, color1 = 0, linewidth1 = 0;

            Circle *c;
            Rectangle *e;
            CircleRect *cr;
            c = new Circle[cno];
            e = new Rectangle[rno];
            cr = new CircleRect[crno];

            cout << endl;
            cout << "TYPE: " << endl;
            cout << "1.....rectangle" << endl;
            cout << "2.....circle" << endl;
            cout << "3.....circle_rectangle" << endl;
            cout << endl;
            cout << "input " << rno << "rectangles" << endl;
            for (j=0; j<rno; j++){
                cout << "enter width, height, type, color, linewidth: " << endl;
                cin >> l >> h >> type1 >> color1 >> linewidth1;
                e[j] = Rectangle(l, h, type1, color1, linewidth1);
                e[j].words = new char[100];
                cout << "enter words: ";
                cin >> e[j].words;
                g[j] = new Rectangle(e[j]);
            }

            cout << "input " << cno << "circles" << endl;
            for(i=j; i<cno+rno; i++){
                cout << "enter radius, type, color, linewidth: " << endl;
                cin >> r >> type >> color >> linewidth;
                c[i] = Circle(r, type, color, linewidth);
                c[i].words = new char[100];
                cout << "enter words: ";
                cin >> c[i].words;
                g[i] = new Circle(c[i]);
            }

            /*
            for(k=i; k>cno+rno+crno; k++){
   cout << "enter width, height, type, color, linewidth for rect and radius , type, color, linewidth for circle: " << endl;
            cin >> l >> h >> type1 >> color1 >> linewidth1 >> r >> type >> color >> linewidth;
            cr[k] = CircleRect(l, h, type1, color1, linewidth1, r, type, color, linewidth);
            cr[k].words = new char[100];
            cout << "enter words: ";
            cin >> cr[k].words;
            g[k] = new CircleRect(cr[i]);
            }
        }
        */

        void Show(){
            cout << endl;
            for(int s=0; s<cno+rno+crno; s++){
                g[s]->ShowMsg();
                cout << endl;
            }
        }
        ~CPPage(){
            cout << endl;
            cout << "Destruction ... done" << endl;
        }
        friend class CPPage;
};

int main(void){
    int rno = 0, cno = 0, crno = 0;
    cout << "enter no of rect, circle, circle_rectangle"  << endl;
    cin >> rno >> cno >> crno;
    CPPage page(rno, cno, crno);
    page.GetInput();
    page.Show();
    return 0;
}
