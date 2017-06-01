#include <stdio.h>

int main(void){
    int n = 0, i = 0, j = 0, k = 0;
    int no3 = 0, sum = 0;
    int pre_no = 0;


    scanf("%d", &n);
    no3 = n * n * n;

    printf("no3: %d\n", no3);

    for(i=1; ; i+=2){
        sum = 0;
        for(j=0; j<n; j++){
            sum += i;
            printf("sum: %d\n", sum);
            if(sum==no3){
                goto end;
            }



                /*
                pre_no = i;
                printf("%d ", pre_no);
                for(; pre_no>0; k-=2){
                    printf("%d ", pre_no);
                }
            }
            */
        }
            printf("next cur");
    }

end:
    return 0;
}

