#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *fp;
    char string[100];
    int i = 0;

    fp = fopen(argv[1], "r"); //

    i = 1;
    while(fgets(string, 100, fp)!=NULL){
        printf("%d %s", i++, string);
    }

    //fgets(string, 100, fp);
    fclose(fp);

    return 0;
}
