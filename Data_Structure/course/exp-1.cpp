#include <iostream>
#include <string.h>

using namespace std;
//求集合的交、并、补

typedef struct{
    string *elem;
    int pre_no; //total number of student
    int max_size;
    int incrementsize;
} Student;

void Init(Student &L, int maxsize, int incresize) {
    L.elem = new ElemType[maxsize];
    L.length = maxsize;
    L.incrementsize = incresize;
}

bool Whether_in(Student stu, string name) {
    string *p = stu.elem;
    p = new string[stu.pre_no];
    
    for(int i=0; i<stu.pre_no; i++) {
        if(*p==name) return 1;
        else p++;
    }
    return 0;
}

void ListTraverse(Student L) {
    for(int i=0; i<L.length; i++) {
        std::cout << L.elem[i] << " ";
    }
} //依次输出L的每个数据元素

string Delete_ele(Student &L, int i) {
     string e = L.elem[i];
     for(int j=i; j<L.pre_no; j++) {
         L.elem[j] = L.elem;
     }
     return e;
}//delete element with index i

void Insert(Student &L, string e) {
    if(L.pre_no<L.max_size) { //already full
        increment(L);
    }
    L.elem[pre_no++] = e;
}

void Increment(Student &L) {
    string *a;

    L.max_size += L.incrementsize;
    a = new string[L.max_size]; //tmp for trans
    for(int i=0; i<L.pre_no; i++) {
        a[i] = L.elem[i];
    } //trans all value

    delete[] L.elem; //free arr
    L.elem = a; 
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
} //???

int main(void){
    
    return 0;
}

