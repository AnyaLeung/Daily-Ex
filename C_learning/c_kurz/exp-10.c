#include <stdio.h>
#include <string.h>
/*
 * 默认6786xxxx-->
 * 结束时间hour:min:sec
 */

int TeleAttr(char *no);

int main(void) {
    int loc = 4;
    float pr = 0.000;
    
    struct Time {
        int hour;
        int min;
        int second;
    };
    
    struct Tele_Info {
        struct Time ymd; //year month date
        char call_no[50]; // 主叫码
        char called_no[50]; //被叫码
        struct Time start_time; //通话开始时间
        struct Time time_len; //通话时长
        float price; //话单价格
    }; //declaration of struct
    
    
    
    struct Tele_Info p[6]; //declaration of struct array
    struct Tele_Info tele;
    struct Tele_Info tmp;
    
    for(int i=0; i<6; i++) {
        scanf("%d-%d-%d ", &tele.ymd.hour, &tele.ymd.min, &tele.ymd.second);
        scanf("%s %s", tele.call_no, tele.called_no); //ymd
        
        scanf("%d:%d:%d", &tele.start_time.hour, &tele.start_time.min, &tele.start_time.second);
        scanf("%d:%d:%d", &tele.time_len.hour, &tele.time_len.min, &tele.time_len.second);
        
        pr = 0;
        
        loc = TeleAttr(tele.called_no);
        switch(loc){
            case 0: pr = tele.time_len.hour * 6 + (tele.time_len.min - 3 + 1) * 0.1 + 3 * 0.2; break;
            case 1: pr = tele.time_len.hour * 36 + (tele.time_len.min + 1) * 0.6; break;
            case 2: pr = tele.time_len.hour * 60 + tele.time_len.min + 1; break;
        }
        tele.price = pr;
        p[i] = tele;
    } //assign and cal price
    
    for(int m=1; m<6; m++) {
        for(int n=0; n<6-m; n++) {
            if(p[n].price<p[n+1].price)
            {
                tmp = p[n];
                p[n] = p[n+1];
                p[n+1] = tmp;
            }
        }
    } //bubble sort, high->low
    
    printf("排序后： ");
    printf("\n");
    for(int s=0; s<6; s++) {
        tele = p[s];
        printf("%d", s+1);
        printf(" %d-%d-%d", tele.ymd.hour, tele.ymd.min, tele.ymd.second);
        printf(" %s %s", tele.call_no, tele.called_no);
        printf(" %d:%d:%d", tele.start_time.hour, tele.start_time.min, tele.start_time.second);
        printf(" %d:%d:%d", tele.time_len.hour, tele.time_len.min, tele.time_len.second);
        printf("\n");
    }
    
    return 0;
}

int TeleAttr(char *called_no) {
    int lena = strlen(called_no);
    if(called_no[0]=='\0') return 1; //domestic
    if(lena==8) return 0; //city
    else return 2; //foreign
} //default 6786xxxx ->
