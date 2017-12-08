#include <iostream>
#include <unistd.h>
#include "TreeNode.h"

using namespace std;

void NotFound(string site){
    cout << "This site can’t be reached." << endl;
    cout << site << "'s server DNS address could not be found." << endl;
    cout << endl;
}

void InitNode(string da, PtrToNode le, PtrToNode ri){

}

int main(void){

    system("open http://www.baidu.com");
    return 0;
}
