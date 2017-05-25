#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stu{
    int no;
    char name[10];
    char major[10];
    int score;
};

struct Stu score[5], temp;
void selection_sort(struct Stu *, int n);

int main(void){
    int i  = 1;
    int n = 0;
    FILE *fp;

    fp = fopen("info.txt", "r");
    while(fscanf(fp, "%d %s %s %d", &score[n].no, score[n].name, score[n].major, &score[n].score)!=EOF)
       n++;

    selection_sort(score, 5);
    for(n=0; n<5; n++){
    printf("%d %s %s %d\n", score[n].no, score[n].name, score[n].major, score[n].score);
    }

    return 0;
}

void selection_sort(struct Stu *, int n){
    int i=0, j=0, k=0;
    for(i=0; i<n-1; i++){
        k = i;
        for(j=i+1; j<n; j++){
            if(score[j].score>score[k].score){
                k = j;
                if(k!=i){
                    temp = score[i];
                    score[i] = score[k];
                    score[k] = temp;
                }
            }
        }
    }
}
