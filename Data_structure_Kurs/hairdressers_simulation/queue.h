#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct{
    int no;
    int barber_wanted_level;
} Customer;

typedef struct{
    int ba_level; 
    bool status; 
    //false-->available, true-->occupied now
} Barber;

typedef struct LNode{
    Customer present_customers;
    struct LNode *next;
}LNode, *LinkList;

typedef LinkList QueuePtr;

//declarations
enum level{
    level_one, level_two, level_three
}; 
//level desc, price 30 60 90

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

void Init_queue(LinkQueue &Q){
    Q.front = new LNode;
    Q.rear = Q.front;
    Q.front->next = NULL;
}

void EnQueue_L(LinkQueue &Q, Customer cu){
    LNode *p;
    p->present_customers = cu;
    p->next = NULL;

    Q.rear->next = p;
    Q.rear = p;
}//Insert into rear

bool DeQueue(LinkQueue &Q, Customer &cu){
    if(Q.front==Q.rear) return false;

    LNode *p;
    p = Q.front->next; //wanna delete
    cu = p->present_customers;
    Q.front->next = p->next;
    if(Q.rear==p) Q.rear = Q.front;
    return true;
}//Delete front, with head left
