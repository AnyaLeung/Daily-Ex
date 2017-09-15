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
           
    L.length += 1;
} //在L的第i个元素前插入e，length+1

void ListDelete(&L, i, &e) {

} //删除第i个元素，并用e返回其值，length-1

void ListTraverse(L) {

} //依次输出L的每个数据元素
