#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Grade_Info{
    int no;
    char name[10];
    char major[10];
    int score;
    struct Grade_Info *next; //本身的指针类型 
};
typedef struct Grade_Info NODE;

void Display_LinkedList(NODE *head);
NODE *Create_LinkedList(), tmp;
    
int main(void){
    Display_LinkedList(Create_LinkedList());
    return 0;
}

NODE *Create_LinkedList(){
   NODE *head, *tail, *pnew; 
   char Name[10];
   char Major[10];
   FILE *fp;
   int score = 0;
   int no = 0;

   if((fp = fopen("score_tab.txt", "r"))==NULL){
       printf("cannot open source file: score_tab.txt\n");
       exit(0);
   }

   head = (NODE *)malloc(sizeof(NODE)); //创建头节点
   head->next =  NULL; //头节点指针域为空(链尾标志
   tail = head;

   while(!feof(fp)){
       fscanf(fp, "%d%s%s%d", &no, Name, Major, &score);

       pnew = (NODE *)malloc(sizeof(NODE));

       pnew->no = no;
       strcpy(pnew->name, Name);
       strcpy(pnew->major, Major);
       pnew->score = score;
       pnew->next = NULL;

       tail->next = pnew;
       tail = pnew;
   }

   fclose(fp);
   return (head);
}

void Display_LinkedList(NODE *head){
    NODE *p;

    for(p=head->next; p!=NULL; p=p->next){
        printf("%d %s %s %d\n", p->no, p->name, p->major, p->score);
    }
    printf("\n");
}  //tail 什么鬼？。。。

void Selection_Sort(NODE *head){
    NODE *p;

    for(p=head->next; p!=NULL; p=p->next){
        
    }
}
