#include <stdio.h>

int main(void){
    struct Student{
        int score;
        struct Student *next;
    }

    typedef struct Student NODE;
    return 0;
}

NODE *Create_LinkList(){
    NODE *head, *tail, *pnew;
    int score = 0;

    head = (NODE *)malloc(siezeof(NODE)); //创建头节点
    
    head->next = NUll; //头下一个空
    tail = head; //尾巴等于头

    while(1){
        scanf("%d", &score);
    }

    if(score<0) break;

    pnew = (NODE*)malloc(sizeof(NODE)); //创建一个新节点

    pnew->score = score;
    pnew->next = NULL; //pnew赋值

    tail->NEXT = pnew; //pnew插入到链表尾巴
    tail = pnew; //尾巴指向新的节点
} //链表的创建

void Insert_LinkList(NODE *head, NODE *pnew, int i){
    NODE *P;
    int j;

    p = head;
    for(j=0; j<i && p!=NULL; j++){
        p = p->next;
    }
    pnew->next = p->next;
    p->next = pnew;
}
