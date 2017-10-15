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

string Delete_ele(Student &L, int i) {
     string e = L.elem[i];
     for(int j=i; j<L.pre_no; j++) {
          L.elem[j] = L.elem;
     }
     return e;
}//delete element with index i

Insert(Student &L, string e) {
}


void Union(Student &stu1, Student stu2) {
    string tmp;
    int i = 0;

    while(!stu2.pre_no) {
        tmp = Delete_ele(stu2, i++);
        if(Whether_in(stu1, tmp)) ;
        else Insert(stu1, tmp);
    }
}

void Diff_set(Student &stu1, Student stu2) { //stu1 - stu2
   string tmp;
   int i = 0;

   while(!stu2.pre_no) {
       tmp = Delete_ele(stu2, i);
       if(!Whether_in(stu1, tmp)) ;
       else {
            Delete_ele(stu1, i++);
       }
   }
}

void Intersaction(Student &stu1, Student &stu2) {
    string tmp;
    int i = 0;
    int sum = (stu2.pre_no > stu1.pre_no)? stu2.pre_no : stu1.pre_no;
    
    while(!stu2.pre_no && !stu1.pre_no) {
       tmp = Delete_ele(stu1, ) 
    }
} //???

int main(void){
    
    return 0;
}

