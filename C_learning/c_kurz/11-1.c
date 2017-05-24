#include <stdio.h>

int main(void){
    struct Student{
        int no;
        int grade;
    }no1, no2;
    int min = 100;
    int min_index = 0;

    typedef struct Student STU;

    STU student[5];
    for(int i=0; i<5; i++){
        scanf("%d %d", &student[i].no, &student[i].grade);
    }

    for(int i=0; i<5; i++){
        if(student[i].grade<100){
            min_index = i;
            min = student[i].grade;
        }
    }

    printf("min_grade: %d, no: %d", min, min_index);

    return 0;
}
