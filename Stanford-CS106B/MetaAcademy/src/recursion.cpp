/* 
 * TODO: put your own comments here. Also you should leave comments on
 * each of your methods.
 */

#include <math.h>
#include "recursion.h"
#include "map.h"
#include "vector.h"
#include "set.h"
#include "gwindow.h"
#include "gobjects.h"
#include "tokenscanner.h"
using namespace std;

/*
 * 最大公分母 Greatest Common Denominator
 */
int gcd(int a, int b) {
    if(b==0) {
        cout << "gcd(" << a << ", " << b << ") = " << a << endl;
        return a;
    }
    else {
        cout << "gcd(" << a << ", " << b << ") = " << "gcd(" << b << ", " << a%b << ")" << endl;
        return gcd(b, a%b);
    }
}

/*
 * Serpinskii 分形
 * write a func named () in meta.cpp
 */
void DrawTri(GWindow &w, int leftX, int leftY, int nsize) {
    GPoint lef;
    GPoint rig;
    GPoint top;
    rig = w.drawPolarLine(leftX, leftY, nsize, -60);
    lef = w.drawPolarLine(leftX, leftY, nsize, -120);
    top = w.drawPolarLine(leftX, leftY, 0, 0);
    w.drawLine(rig, lef);
}

void serpinskii(GWindow &w, int leftX, int leftY, int size, int order) {
    DrawTri(w, leftX, leftY, size);
    cout << "[recursion serpinskii called]" << endl;
}

int floodFill(GBufferedImage& image, int x, int y, int newColor) {
    //if(x>image.getWidth()||y>image.getHeight());
    //else {
        image.setRGB(x, y, newColor);

      floodFill(image, x+1, y, newColor);
      floodFill(image, x, y+1, newColor);
      floodFill(image, x-1, y, newColor);
      floodFill(image, x, y-1, newColor);
  //  }
    return 0;
}

void personalCurriculum(Map<string, Vector<string>> & prereqMap,string goal) {
    // your code here
    cout << "[recursion personal curriculum called]" << endl;
}

string generate(Map<string, Vector<string> > & grammar, string symbol) {
    // your code here
    cout << "[recursion generate called]" << endl;
    return "";
}
