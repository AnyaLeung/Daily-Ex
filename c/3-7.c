#include <stdio.h>

int main(void)
{
        int a, b;

        printf("enter two int: \n");

        printf("enter a here:");                scanf("%d", &a);
        printf("enter b here:");                scanf("%d", &b);

        if (a != b)
                puts("a isnt equal with b");
        else
                puts("a  equal with b");

        return 0;
}

