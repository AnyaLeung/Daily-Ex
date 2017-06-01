#include <stdio.h>

int main(void){
    int n = 0, i = 0, j = 0, k = 0;
    int no3 = 0, sum = 0;
    int pre_no = 0, add = 0, temp_i = 0;

    scanf("%d", &n);
    no3 = n * n * n;

    for(i=1; ; i+=2){
        sum = 0;
        add = i;
        temp_i = i;
        for(j=0; j<n; j++){
            sum += add;
            add += 2;
            if(sum==no3){
                for(k=0; k<n; k++){
                    printf("%d ", temp_i);
                    temp_i += 2;
                }
                goto end;
            }
        }
    }
end:
    printf("\n");
    return 0;
}
