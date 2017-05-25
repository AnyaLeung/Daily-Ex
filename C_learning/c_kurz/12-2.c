#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *input1, *input2, *output;
    input1 = fopen(argv[1], "r");
    input2 = fopen(argv[2], "r");
    output = fopen(argv[3], "r+");

    char string[100];

    while(fgets(string, 100, input1)!=NULL){
        fputs(string, output);
    }

    while(fgets(string, 100, input2)!=NULL){
        fputs(string, output);
    }
    
    fclose(input1);
    fclose(input2);
    fclose(output);

    return 0;
}
