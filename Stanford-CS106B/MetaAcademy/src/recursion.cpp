/*
 * 我再也不改主函数了，真的QAQ
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

int Filler(GBufferedImage& image, int x, int y, int newColor, int originalColor);
void GenerateCur(Map<string, Vector<string>> & prereqMap,string goal, Set<string> &Result);
string gene(Map<string, Vector<string>>& grammar, string symbol, string& currentSentence);


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
void DrawTri(GWindow& w, int leftX, int leftY, int size) {
    w.drawLine(leftX+size/2, leftY, leftX+size/4, leftY+((sqrt(3)*size)/4));
    w.drawLine(leftX+size/2, leftY, leftX+3*size/4, leftY+((sqrt(3)*size)/4));
    w.drawLine(leftX+size/4, leftY+((sqrt(3)*size)/4), leftX+size/2, leftY+((sqrt(3)*size)/4));
}

void serpinskii(GWindow& w, int leftX, int leftY, int size, int order) {
    if (order==0) {
        return;
    } else if(order==1) {
        w.drawLine(leftX, leftY, leftX+size, leftY);
        w.drawLine(leftX, leftY, leftX+size/2, leftY+((sqrt(3)*size)/2));
        w.drawLine(leftX+size, leftY, leftX+size/2, leftY+((sqrt(3)*size)/2));
    } else {
        DrawTri(w, leftX, leftY, size);

        serpinskii(w, leftX, leftY, size/2, order-1);
        serpinskii(w, leftX+size/2, leftY, size/2, order-1);
        serpinskii(w, leftX+size/4, leftY+((sqrt(3)*size)/4), size/2, order-1);
    }
}


/*
 * 涂地板...
 */
int floodFill(GBufferedImage& image, int x, int y, int newColor) {
    if (image.inBounds(x, y)){
        return Filler(image, x, y, newColor, image.getRGB(x,y));
    }
    return 0;
}

int Filler(GBufferedImage& image, int x, int y, int newColor, int originalColor) {
        if(image.inBounds(x+1, y)&& originalColor==image.getRGB(x+1, y)) {
            image.setRGB(x + 1, y, newColor);
            Filler(image, x + 1, y, newColor, originalColor);
        }
        if(originalColor==image.getRGB(x, y-1)&& image.inBounds(x, y+1)) {
            image.setRGB(x, y + 1, newColor);
            Filler(image, x, y + 1, newColor, originalColor);
        }
        if(originalColor==image.getRGB(x-1, y)&& image.inBounds(x-1, y)) {
            image.setRGB(x - 1, y, newColor);
            Filler(image, x - 1, y, newColor, originalColor);
        }
        if(originalColor==image.getRGB(x, y-1)&& image.inBounds(x, y-1)) {
            image.setRGB(x, y - 1, newColor);
            Filler(image, x, y - 1, newColor, originalColor);
        }
    return 0;
}

/*
 * generate curriculum
*/
void personalCurriculum(Map<string, Vector<string>> & prereqMap,string goal) {
    Set<string> Result;
    GenerateCur(prereqMap, goal, Result);
    cout << goal << endl;
}

void GenerateCur(Map<string, Vector<string>> & prereqMap,string goal, Set<string> &Result){
    Vector<string> directConcept;
    directConcept = prereqMap.get(goal);
    for(string childConcept: directConcept) {
        if(!Result.contains(childConcept)) {
            Result.add(childConcept);
            cout << childConcept << endl;
            GenerateCur(prereqMap, childConcept, Result);
        }
        else break;
    }
}
//class set
//for(:)

/*
 *generate Q
 */
string generate(Map<string, Vector<string>>& grammar, string symbol) {
    string currentSentence = "";
    if (!grammar.containsKey(symbol)) {
        return symbol;
    }
    return gene(grammar, symbol, currentSentence);
}

string gene(Map<string, Vector<string>>& grammar, string symbol, string& currentSentence) {
    Vector<string> grammarRule = grammar.get(symbol);
    int randNum = randomInteger(0, grammarRule.size()-1); //range 0~(size-1)
    string rule = grammarRule.get(randNum);

    TokenScanner scanner(rule);
    string token;
    while (scanner.hasMoreTokens()) {
        token = scanner.nextToken();
        if (!grammar.containsKey(token)) {
            currentSentence += token + "";
        } else {
            gene(grammar, token, currentSentence);
        }
    }
    return currentSentence;
}
