#include <stdio.h>

int main(void){
    int no = 0;
    int i = 0;
    int j = 0;
    int sum = 0;
    int no3 = 0;
    int flag = 0;
    int  *rem;
    int k = 0;

    scanf("%d", &no);
    no3 = no * no * no;

    for(i=1; i<no&& flag==0; i+=2){
        for(j=0; j<no; j++){
            sum += i;
            if(sum==no3) {
                break;
                flag = 1;
            }
        }
    }

    for(k=0; k<no; k++){
        printf("%d", i);
        i -= 2;
    }

    return 0;
}

