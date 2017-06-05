#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * 链表的创建，插入，删除，输出和销毁
 */

struct Grade_Info{
    int score;
    struct Grade_Info *next; //本身的指针类型 
};
typedef struct Grade_Info NODE;

NODE *Create_LinkedList();
    
int main(void){
    Create_LinkedList();
    return 0;
}

NODE *Create_LinkedList(){
   NODE *head, *tail, *pnew; //定义头指针，尾指针，新指针
   int score = 0;

   head = (NODE *)malloc(sizeof(NODE)); //创建头节点
   head->next =  NULL; //头节点指针域为空(链尾标志
   tail = head;

   while(score>=0){
       scanf("%d", &score);

       pnew = (NODE *)malloc(sizeof(NODE));

       pnew->score = score;
       pnew->next = NULL;

       tail->next = pnew;
       tail = pnew;
   }
   return (head);
}

void Insert_LinkedList(NODE *head, NODE *pnew, int i){
   NODE *p; 

   for(int j=0; j<i&&p!=NULL; j++){
       p = p->next;
   }

   pnew->next = p->next;
   p->next = pnew;
   //顺序不能颠倒
} 
//把pnew插入到第i个节点前，第i+1个节点后

void Delete_LinkedList(NODE *head, int i){
    NODE *p, *q;
    int j;

    p = head;
    for(int j=1; j<i&&p->next!=NULL; j++){
        p = p->next;
    }

    q = p->next; //q指向想删除的节点i
    p->next = q->next; //删除节点i
    free(q); //释放q的内存空间
}

void Display_LinkedList(NODE *head){
    NODE *p;

    for(p=head->next; p!=NULL; p=p->next){
        printf("%d ", p->score);
    }
    printf("\n");
} //显示链表

void Free_LinkList(NODE *head){
    NODE *p, *q;

    p = head;
    while(p->next!=NULL){
        q = p->next;
        p->next = q->next;
        free(q);
    }
    free(head);
} //销毁链表
