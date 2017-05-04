#include<stdio.h>

int main() {
    long n = 0, high = 0, low = 0, change = 0;
    int flag1 = 0, flag2 = 0;

    scanf("%lx",&n);
    printf("n: %#lx\n",n); //# for..?

    high = (n>>16)&0x0000ffff; //move high 16 bit to low
    low = n & 0x0000ffff;
    flag1 = (high%2)? 1: 0;
    flag2 = (low%2)? 1: 0;
    printf("0为偶数，1为奇数\n") ;
    printf("high: %#lx ------%d\nlow: %#lx------%d\n",high,flag1,low,flag2) ;

    change = ((n&0x00ff0000)>>8) + ((n&0x0000ff00)<<8) + ((n&0x000000ff)<<24) + ((n&0xff000000)>>24) ;
    printf("after change: %#lx\n",change) ;

    return 0 ;
}
