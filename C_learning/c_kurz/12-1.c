#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int i = 2, j = 0;
    char ch;
    FILE *fp;

    if((fp=fopen(argv[1], "rt"))==NULL){
        printf("cannot open!");
        exit(0);
    }

    if(argc!=2){
        printf("wrong arg number!\n");
    }

    printf("1 ");

    for(; !feof(fp); ){
        ch = fgetc(fp);
        printf("%c", ch);
        if (ch=='\n'){
            printf("%d ", i++);
        }
    }

    fclose(fp);
    return 0;
}
