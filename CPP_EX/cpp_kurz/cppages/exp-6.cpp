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
        virtual void ShowMsg() = 0;
        virtual void ReadInfo(){};
        virtual ~CGraph(){};
};

class Rectangle: public CGraph{
    private:
        char id;
        int width, height;
        char *words;
        int type, color, linewidth;

    public:
        Rectangle(int l=0, int h=0, int type=1, int color=0, int linewidth=0){
            width = l;
            height = h;
            id = '1';
            type = type;
            color = color;
            linewidth = linewidth;
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
        }

        ~Rectangle(){}

        friend class CPPage;
};

class Circle: public CGraph{
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
        }

        ~Circle(){}

        friend class CPPage;
};

class CPPage{
    public:
        int rno;
        int cno;
        CGraph *g[100];
        CPPage(int rno = 0, int cno = 0){
            this->rno = rno;
            this->cno = cno;
        }

        void GetInput(){
            int r = 0, h = 0, l = 0;
            int i = 0;
            int j = 0;
            int type=0, color=0, linewidth=0;

            Circle *c;
            Rectangle *e;
            c = new Circle[cno];
            e = new Rectangle[rno];

            cout << endl;
            cout << "TYPE: " << endl;
            cout << "1.....rectangle" << endl;
            cout << "2.....circle" << endl;
            cout << endl;

            cout << "input " << cno << "circles" << endl;
            for(i=0; i<cno; i++){
                cout << "enter radius, type, color, linewidth: " << endl;
                cin >> r >> type >> color >> linewidth;
                c[i] = Circle(r, type, color, linewidth);
                g[i] = new Circle(c[i]);
            }

            cout << "input " << rno << "rectangles" << endl;
            for (j=i; j<rno+cno; j++){
                cout << "enter width, height, type, color, linewidth: " << endl;
                cin >> l >> h >> type >> color >> linewidth;
                e[j] = Rectangle(l, h, type, color, linewidth);
                g[i] = new Rectangle(e[i]);
            }

        }

        void Show(){
            int k = 0;
            cout << endl;
            for(k=0; k<cno+rno; k++){
                g[k]->ShowMsg();
                cout << endl;
            }
        }

        ~CPPage(){
            cout << endl;
            cout << "Destruction ... done" << endl;
        }
};

int main(void){
    int rno = 0, cno = 0;
    cout << "enter no of rect, circle: "  << endl;
    cin >> rno >> cno;
    CPPage page(rno, cno);
    page.GetInput();
    page.Show();
    return 0;
}
