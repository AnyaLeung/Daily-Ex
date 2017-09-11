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
 *
 * 将实验五的CGraph改为抽象类，（设计纯虚函数ShowMsg)。
 *
 * 修改实验五重的CRect, CCircle类，设计函数ShowMsg显示其所有信息。
 *
 * 修改CPPage类，原来的组合成员的类型改为CGraph*,并使用虚函数的方式，通过调用虚函数的方式，通过调用CGraph的指针调用ShowMsg，显示每个对象的信息 (...)
 *
 */

class CPPage{
    public:
        CGraph* cg;
        norec, nocir;
        void ReadRect_n_Circle(){
            rectangle []; //norec
            //nocir
            cg new;
            cg[i] = rectangle[i];
        }
        show(){
            for(int i=0; i<no+no; i++){
                cg[i]->showMsg();
            }
        }
};

class CGraph{
    private:
    int type;
    int color;
    int linewidth;

    virtual void ShowMsg = 0;
    virtual ~CGraph();

    void Show(){
        cout << type << color << linewidth << endl;
    }
};

Class CRect: virtual public CGraph{
    private:
        int width;
        int height;
        char *words;
    public:
        CRect();
        ~CRect();
        void ReadInfo(){
            words = new char[width-4];
            cin >> words;
        }
};

Class CCircle{};

class CCR: public Circle, public Rectangle{
    public:
        CCR(int r=0, int l=0, int ): CGraph(), Rectnale(), {
        }
};
int main(void){

}
