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
    L.elem = new string[maxsize];
    L.max_size = maxsize;
    L.incrementsize = incresize;
    L.pre_no = 0;
} //create a linear list with student info

bool Whether_in(Student stu, string name) {
    string *p;
    p = new string[stu.pre_no];
    p = stu.elem;
    
    for(int i=0; i<stu.pre_no; i++) {
        if(*p==name) return 1;
        else p++;
    }
    return 0;
} //judge whether a name string is included in stu

void ListTraverse(Student L) {
    for(int i=0; i<L.pre_no; i++) {
        cout << L.elem[i] << " ";
    }
} //cout elements in L

string Delete_ele(Student &L, int i) {
    string e = L.elem[i];
    for(int j=i; j<L.pre_no; j++) {
        L.elem[j] = L.elem[j+1];
    }
    L.pre_no--;
    return e;
}//delete element with index i

void Delete_with_value(Student &L, string tmp) {
    for(int i=0; i<L.pre_no; i++) {
        if(L.elem[i]==tmp) {
            for(int j=i; j<L.pre_no-1; j++) {
                L.elem[j] = L.elem[j + 1];
            }
        }
    }
    L.pre_no--;
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

void Insert(Student &L, string e) {
    if(L.pre_no<L.max_size) { //already full
        Increment(L);
    }
    L.elem[L.pre_no++] = e;
} //insert string e into end

void Copy_stu(Student stu1, Student &stu2) {
    stu2.max_size = stu1.max_size;
    stu2.pre_no = stu1.pre_no;
    stu2.incrementsize = stu1.incrementsize;
    stu2.elem = new string[stu1.pre_no];
    for(int i=0; i<stu1.pre_no; i++) {
        stu2.elem[i] = stu1.elem[i];
    }
}

void Union(Student &stu1, Student stu2) {
    string tmp;
    
    while(stu2.pre_no) {
        tmp = Delete_ele(stu2, 0); //delete element with index i
        
        if(Whether_in(stu1, tmp)) ;
        else {
            Insert(stu1, tmp);
        }
    }
} //union two linear lists

void Diff(Student &stu1, Student &stu2) { //stu1 - stu2
    string tmp;
    
    while(stu2.pre_no) {
        tmp = Delete_ele(stu2, 0);
        
        if(!Whether_in(stu1, tmp)) ;
        else {
            Delete_with_value(stu1, tmp);
        }
    }

} //get difference set of stu1 & stu2

void Intersaction(Student stu1, Student stu2, Student &stu3) {
    string tmp;
    
    while(stu2.pre_no) {
        tmp = Delete_ele(stu2, 0);
        if(Whether_in(stu1, tmp)) {
            Insert(stu3, tmp);
        }
    }
}

int main(void){
    Student stu1, stu2, stu3, stu4, stu5, stu6, stu7;
    //stu1 = stu3 = stu5 --> a, b
    //stu2 = stu4 = stu6 --> a, c, d, e
    //stu7        --> intersaction of stu1 & stu2
    
    Init(stu1, 30, 10);
    Init(stu2, 30, 10);
    Init(stu7, 30, 10);
   
    Insert(stu1, "stu_a");
    Insert(stu1, "stu_b");
    Insert(stu2, "stu_a");
    Insert(stu2, "stu_c");
    Insert(stu2, "stu_d");
    Insert(stu2, "stu_e");
    
    Copy_stu(stu1, stu3);
    Copy_stu(stu1, stu5);
    Copy_stu(stu2, stu4);
    Copy_stu(stu2, stu6);
    
    cout << "a: ";
    ListTraverse(stu1);
    cout << endl;
    
    cout << "b: ";
    ListTraverse(stu2);
    cout << endl;
    cout << endl;
    
    Union(stu1, stu2);
    cout << "The union of a & b is: " << endl;
    ListTraverse(stu1);
    cout << endl;
    cout << endl;
    //并集

    Diff(stu3, stu4);
    cout << "The difference set of a & b is: " << endl;
    ListTraverse(stu3);
    cout << endl;
    cout << endl;
    //差集
    
    Intersaction(stu5, stu6, stu7);
    cout << "The intersaction of a & b is: " << endl;
    ListTraverse(stu7);
    cout << endl;
    cout << endl;
    //交集
    
    return 0;
}
