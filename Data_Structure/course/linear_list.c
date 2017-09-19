#include <iostream>
#include <string.h>

#define ElemType char

typedef struct {
    ElemType *elem;
    int length;
    int incrementsize;
} Sqlist;

void Init(Sqlist &L, int maxsize, int incresize) {
    L.elem = new ElemType[maxsize];
    L.length = maxsize;
    L.incrementsize = incresize;
}

void DestroyList(Sqlist &L) {
    delete[] L.elem;
    L.length = 0;
    L.incrementsize = 0;
}

void ClearList(Sqlist &L) {
    std::fill_n(L.elem, L.length, 0);
}

bool ListEmpty(Sqlist L) {
    if(L.length) return true;
    return false;
}

void GetElem(Sqlist L, int i, ElemType &e) {
    e = L.elem[i];
} //return L[i] value, with e

int LocateElem(Sqlist L, ElemType e) {
    for (int i=0; i<L.length; i++) {
        if (L.elem[i]==e) return i;
    }
    return 0;
}

void PriorElem(Sqlist L, ElemType cur_e, ElemType &pre_e) {
    for(int i=0; i<L.length; i++) {
        if(L.elem[i]==cur_e) {
            pre_e = L.elem[i-1];
        }
    }
}

void NextElem(Sqlist L, ElemType cur_e, ElemType &next_e) {
    for(int i=0; i<L.length; i++) {
        if(L.elem[i]==cur_e) {
            next_e = L.elem[i+1];
        }
    }
}

int ListDelete(Sqlist &L, int i, ElemType &e) {
    e = L.elem[i-1];
    for(int j=i-1; j<L.length; j++) {
        L.elem[j] = L.elem[j+1];
    }
    L.length -= 1;
    return e;
} //删除第i个元素，并用e返回其值，length-1


void ListTraverse(Sqlist L) {
    for(int i=0; i<L.length; i++) {
        std::cout << L.elem[i] << " ";
    }
} //依次输出L的每个数据元素

int main(void) {
    char e;
    Sqlist L;
    Init(L, 10, 10);
    char tmp[10] = "abcdefghi";
    strcpy(L.elem, tmp);
    
    std::cout << "empty? " << std::endl;
    std::cout << ListEmpty(L) << std::endl;
    
    GetElem(L, 3, e);
    std::cout << e;
    std::cout << std::endl;
    
    std::cout << LocateElem(L, 'b');
    
    return 0;
}
