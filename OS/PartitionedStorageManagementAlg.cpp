#include <iostream>
#include <queue>
#include <stdlib.h>
#include <vector>
#include <list>

using namespace std;

/* globle variables definitions */
class PROCESS{
    public:
        int size;

        PROCESS(int s);
};

class TABLE{
    public:
        int capability;

        TABLE(int c);
};


PROCESS::PROCESS(int s){
    size = s;
}

TABLE::TABLE(int c){
    capability = c;
}

vector<PROCESS> process_list;
list<TABLE> free_tables;
list<TABLE> used_tables;
//10 17 9 12 3 14 
//10mb, 20, 4, 18, 7, 9, 12, 15
void Init(void){
    PROCESS pro0(10);
    process_list[0] = pro0;
    PROCESS pro1(17);
    process_list[1] = pro1;
    PROCESS pro2(9);
    process_list[2] = pro2;
    PROCESS pro3(12);
    process_list[3] = pro3;
    PROCESS pro4(3);
    process_list[4] = pro4;
    PROCESS pro5(14);
    process_list[5] = pro5;

    TABLE tab0(10);
    used_table.insert()
}


/* globle variables definitions end*/

int main(void){
    process_list.reserve(6);
    return 0;
}
