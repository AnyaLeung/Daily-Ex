#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NUM 100

FILE *fp1;
struct stu_info{
	int rank;
	char no[10];
	char name[10];
	int score;
	char major[20];
	struct stu_info *next;
};

typedef struct stu_info NODE;

NODE *head;
NODE *creat_link(){
    struct stu_info *tail,*pnew;
    head=(NODE *)malloc(sizeof(NODE));

    if(head==NULL){
        printf("no enough memory");
        exit(0);
    }

    head->next=NULL;
    tail=head;

    while(true){
        pnew=(NODE *)malloc(sizeof(NODE));
        if(pnew==NULL){
            printf("no enough memory");
            return (NULL);
        }
        if(fscanf(fp1,"%s%s%d%s",pnew->no,pnew->name,&pnew->score,pnew->major)==EOF)
            break;
        pnew->next=NULL;
        tail->next=pnew;
        tail=pnew;
    }
    return (head);
}

int main(void){
    NODE score[100], temp;
    int i = 0, j = 0, max_index = 0, s = 0, t = 0, n = 0;
    FILE *fp2;

    fp1=fopen("score.txt","r");
    fp2=fopen("result.txt","w");

	while(fscanf(fp1,"%s%s%d%s",score[n].no, score[n].name, &score[n].score, score[n].major)!=EOF)
		n++;

	for(i=0; i<n-1; i++){
		max_index=i;
		for(j=i+1;j<n;j++){
			if(score[j].score>score[max_index].score)
				max_index=j;
		}
		if(max_index!=i){
			temp=score[i];
			score[i]=score[max_index];
			score[max_index]=temp;
		}
	} //selection sort

	for(i=0; i<n; i++){
		if(score[i].score!=s){
			j++;
			score[i].rank=j;
			s=score[i].score;
		}
		score[i].rank=j;
	}

	
	for(i=0; i<n; i++){
		printf("%s %s %d %s\n", score[i].no, score[i].name, score[i].score, score[i].major);
	}
		for(i=0; i<n; i++){
		fprintf(fp2,"%s %s %d %s\n",  score[i].no, score[i].name, score[i].score, score[i].major);
	}
	
	
	fclose(fp1);
	fclose(fp2);
}
