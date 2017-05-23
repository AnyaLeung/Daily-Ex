#include <stdio.h>

void Welcome_Page(void);

int main(void){
    int n = 0; 
    char string[40];
    FILE *fp;

    Welcome_Page();
    scanf("%d", &n);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    switch(n){
        case 1: fp = fopen("小绍兴白斩鸡.txt", "r"); break;
        case 2: fp = fopen("老大房鲜肉月饼.txt", "r"); break;
        case 3: fp = fopen("德兴馆焖蹄面.txt", "r"); break;
        case 4: fp = fopen("城隍庙五香豆.txt", "r"); break;
        case 5: fp = fopen("崇明糕.txt", "r"); break;
        case 6: fp = fopen("高桥松饼.txt", "r"); break;
        case 7: fp = fopen("南翔小笼.txt", "r"); break;
        case 8: fp = fopen("荠菜肉丝炒年糕.txt", "r"); break;
        case 9: fp = fopen("两面黄.txt", "r"); break;
        case 10: fp = fopen("烂糊面.txt", "r"); break;
    }

    while(fgets(string, 40, fp)!=NULL){
        printf("%s", string);
    }

    fclose(fp);
    return 0;
}

void Welcome_Page(void){
    printf("\n\n\n");
    printf("          ");
    printf("上海小吃\n");
    printf("          ");
    printf("1-----小绍兴白斩鸡\n");
    printf("          ");
    printf("2-----老大房鲜肉月饼\n");
    printf("          ");
    printf("3-----德兴馆焖蹄面\n");
    printf("          ");
    printf("4-----城隍庙五香豆\n");
    printf("          ");
    printf("5-----崇明糕\n");
    printf("          ");
    printf("6-----高桥松饼\n");
    printf("          ");
    printf("7-----南翔小笼\n");
    printf("          ");
    printf("8-----荠菜肉丝炒年糕\n");
    printf("          ");
    printf("9-----两面黄\n");
    printf("          ");
    printf("10-----烂糊面\n");
    printf("          ");
    printf("请输入你感兴趣的");
}
