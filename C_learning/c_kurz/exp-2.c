#include<stdio.h>

int main() {
    long n = 0, high = 0, low = 0, change = 0;
    int flag1 = 0, flag2 = 0; //flag for odd/even number

    scanf("%lx",&n);
    printf("n: %#lx\n",n); //输入一个长整型数字

    high = (n>>16) & 0x0000ffff; //move high 16 bits to low
    low = n & 0x0000ffff;
    flag1 = (high%2)? 1: 0;
    flag2 = (low%2)? 1: 0;
    printf("0为偶数，1为奇数\n") ;
    printf("high: %#lx ------%d\nlow: %#lx------%d\n",high,flag1,low,flag2);
    //判断高十六位和第十六位的奇偶

    change = ((n&0x00ff0000)>>8) + ((n&0x0000ff00)<<8) + ((n&0x000000ff)<<24) + ((n&0xff000000)>>24) ;
    printf("after change: %#lx\n",change) ;

    return 0 ;
}

