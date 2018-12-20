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
    int start_add;
    int end_add;
    
    PROCESS(int s);
};

class TABLE{
public:
    int capability;
    int start_add;
    int end_add;
    int id;
    
    TABLE(int c, int sa, int i);
    bool operator == (const TABLE& t) const { return id == t.id; }

};


PROCESS::PROCESS(int s){
    size = s;
    start_add = -1;
    end_add = -1;
}

TABLE::TABLE(int c, int sa, int i){
    capability = c;
    start_add = sa;
    end_add = start_add + capability * 1024;
    id = i;
}

int process_count = 0;
vector<PROCESS> process_list;
list<TABLE> free_tables;
list<TABLE> used_tables;
//10 17 9 12 3 14
//10kb, 20, 4, 18, 7, 9, 12, 15
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
    PROCESS pro5(8);
    process_list[5] = pro5;
    
    TABLE tab0(10, 1000, 0);
    free_tables.push_back(tab0);
    TABLE tab1(20, tab0.end_add+1, 1);
    free_tables.push_back(tab1);
    TABLE tab2(4, tab1.end_add, 2);
    free_tables.push_back(tab2);
    TABLE tab3(18, tab2.end_add, 3);
    free_tables.push_back(tab3);
    TABLE tab4(7, tab3.end_add, 4);
    free_tables.push_back(tab4);
    TABLE tab5(9, tab4.end_add, 5);
    free_tables.push_back(tab5);
    TABLE tab6(12, tab5.end_add, 6);
    free_tables.push_back(tab6);
    TABLE tab7(16, tab6.end_add, 7);
    free_tables.push_back(tab7);
}
/* globle variables definitions end*/

void Print(void){
    ;
}

void RaiseError(PROCESS pro){
    cout << "no enough space for process size" << pro.size << endl;
}

bool Allo(PROCESS p){
    list <TABLE>::iterator it;
    for(it=free_tables.begin(); it!=free_tables.end(); it++){
        cout << it->capability << "  " << it->id << endl;
            if((it->capability)>=(p.size)){
            cout << "table cap: " << it->capability << " " << "table id" << it->id << " ";
            cout << "psize: " << p.size << endl;
            if((it->capability)==p.size){
                free_tables.remove(*it);
                used_tables.push_back(*it);
                return true;
            }
            else{
                TABLE neut(it->capability-p.size , it->start_add+p.size*1024, it->id);
                //cout << "id: " << neut.id << endl;
                //cout << neut.capability << "  " << neut.start_add << "  " << neut.end_add << endl;
                //cout << it->capability << "  " << it->start_add << "  " << it->end_add << endl;
                free_tables.insert(it, neut);
                used_tables.push_back(*it);
                auto tmpElem = *it;
                it = free_tables.erase(it);
                //cout << "pre:" << it->capability << endl;
                free_tables.insert(it, tmpElem);
                return true;
            }
        }
    }
    return false;
}

void FFA(void){
    while(process_count<6){
        if(!Allo(process_list[process_count])){
            RaiseError(process_list[process_count]);
        }
        //cout << "ok";
        process_count++;
    }
    
}

int main(void){
    process_list.reserve(6);
    Init();
    FFA();
    
    return 0;
}

