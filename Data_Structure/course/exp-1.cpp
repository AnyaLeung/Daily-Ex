#include <iostream>

using namespace std;
//求集合的交、并、补

typedef struct{
    string *elem;
    int pre_no; //total number of student
    int max_size;
} Student;

bool Whether_in(Student stu, string name) {
    string *p = stu.elem;
    p = new string[stu.pre_no];
    
    for(int i=0; i<stu.pre_no; i++) {
        if(*p==name) return 1;
        else p++;
    }
    return 0;
}

string Delete_ele(Student &L, int i, string &e) {
     e = L.elem[i];
     for(int j=i; j<L.pre_no; j++) {
          L.elem[j] = L.elem
     }
     
}//delete element with index i

Student* Intersaction(Student stu1, Student stu2) {
    for(int i=0; i<stu1.pre_no+stu2.pre_no; i++) {
        
    }
    return ;
}

int main(void){
    
    return 0;
}

