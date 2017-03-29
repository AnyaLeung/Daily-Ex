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
int ChangeAndSum( GBufferedImage& image , int x ,int y , int newColor ,int old );


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
void serpinskii(GWindow &w, int leftX, int leftY, int size, int order) {
    // your code here
    cout << "[recursion serpinskii called]" << endl;
    if (order == 1 ){

        w.drawLine(leftX,leftY,size+leftX,leftY) ;
        w.drawLine(size+leftX,leftY,size / 2 + leftX , size*sqrt(3) /2+ leftY) ;
        w.drawLine(size/2 +leftX,size*sqrt(3)/2+leftY,leftX,leftY) ;
    }

    else if ( order <= 0 ){

        throw ("wrong!") ;
        return ;
    }

    else {

        serpinskii (w , leftX - size/4 , leftY + size*sqrt(3)/4 ,size /2, order - 1 ) ;
        serpinskii (w , leftX + size /4 , leftY - size*sqrt(3)/4 , size/2 , order - 1 ) ;
        serpinskii (w,  leftX  + 3*size /8 , leftY + size/4 *sqrt(3), size /2 ,order - 1 ) ;

    }
}


/*
 * 涂地板...
 */
int floodFill(GBufferedImage& image, int x, int y, int newColor) {
    // your code here
    int old = 0;
    old = image.getRGB(x,y) ;
    if ( newColor == old ) {
        return 0;
    }

    else
        return ChangeAndSum(image , x, y , newColor , old ) ;
}

int ChangeAndSum( GBufferedImage& image , int x ,int y , int newColor ,int old ) {

    if ( image.inBounds(x,y) && image.getRGB(x,y)==old) {

        image.setRGB( x , y , newColor );
        return 1 + ChangeAndSum(image,x,y+1,newColor,old) + ChangeAndSum(image,x,y-1,newColor,old) + ChangeAndSum(image,x+1,y,newColor,old) + ChangeAndSum(image,x-1,y,newColor,old) ;
    }

    else return 0 ;
}

/*
 * generate curriculum
*/
void personalCurriculum(Map<string, Vector<string>> & prereqMap,string goal) {
    Set<string> Result;
    GenerateCur(prereqMap, goal, Result);
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
        else cout << goal << endl;
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
    //get rule  from the map for your current symbol
    int randNum = randomInteger(0, grammarRule.size()-1); //range from 0 to (size-1)
    string rule = grammarRule.get(randNum);
    //get a random rule from those rules

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
