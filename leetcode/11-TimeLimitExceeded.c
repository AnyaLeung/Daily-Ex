#include <stdio.h>
#include <stdlib.h>

//f**k
int maxArea(int* height, int heightSize) {
    int max = 0, p = 0;
    int klein = 0, pre = 0;

    for(int i=1; i<=heightSize-1; i++){
        for(int j=i+1; j<=heightSize; j++){
            klein = (height[i-1] < height[j-1])? height[i-1] : height[j-1];
            pre = (j - i) * klein;
            max = (max>pre)? max:pre;
        }
    }
    return max;
}

int main(void){
    int height[5] = {2, 1, 3, 4, 5};

    printf("%d", maxArea(height, 5));
    return 0;
}
//Brute Force的结果果断是超时啊QAQ 太慢太慢 伤心T T
