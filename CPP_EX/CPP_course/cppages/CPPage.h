#include <iostream>
#include "rectangle.h"
using namespace std;

class Rectangle;

class CPPage{
    private:
        Circle cir1[2];
        Rectangle rect[2];
        static int countR;
        static int countC; //count circle
    public:
        Rectangle(Circle cir1, Circle cir2){
            this->cir1[0] = cir1;
            this->cir2[1] = cir2;
        }
        Rectangle(Rectangle rect1, Rectangle rect2){
            this->rect[0] = rect1;
            this->rect[1] = rect2;
        }

        void Show(Circle cir){
            cout << "we have " << Rectangle.countR << "rectangles in pages" << endl;
            cout << "we have " << Circle.countC << "circles in pages" << endl;
            cout << "rec words are" << cir.words << endl;
        }
};

int CPPage::countR = 0;
int CPPage::countC = 0;

