#include <iostream>
#include <stdlib.h>

#define ElemType char

using namespace std;

typedef struct {
    ElemType *elem;
    int length;
    int incrementsize;
} Sqlist;

void Init(Sqlist &L, int maxsize=LIST_INIT_SIZE, int incresize=LISTINCREMENT) {
    L.elem = new ElemType[maxsize];
    L.listsize = maxsize;
    L.incrementsize = incresize;
}


void DestroyList(Sqlist &L) {
    delete[] L.elem;
    L.length = 0;
    L.incrementsize = 0;
}

void ClearList(Sqlist &L) {
    std::fill_n(L.elem, length, 0);
}

bool ListEmpty(L) {
    if(length) return true;
    return false;
}

void GetElem(L, i, &e) {
    e = L.elem[i];
} //return L[i] value, with e

int LocateElem(L, e) {
    for (int i=0; i<length; i++) {
        if (L.elem[i]==e) return i;
    }
    return 0; 
}

void NextElem(L, cur_e, &next_e) {
    for (int i=0; i<length; i++) {
        if(L.elem[i]==cur_e) {
            next_e = L.elem[i+1];
        }
    }
}

void ListInsert(&L, i, e) {

}
