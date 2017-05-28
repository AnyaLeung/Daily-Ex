#include <stdio.h>
#include <string.h>

void GetSubString(char string[]);
void Insert(char string[]);
void Delete(char string[]);

char subs[100];
char string[100];
char str[100];
char inserts[200];

int main(void){
    int choice = 0;
    
    printf("1---------取子串\n");
    printf("2---------插入操作\n");
    printf("3---------删除操作\n");
    printf("\n");
    
    printf("输入你想要的操作：");
    scanf("%d", &choice);
    
    switch(choice){
        case 1: {
            GetSubString(string);
            
        } break;
        case 2: {
            Insert(string);
        } break;
        case 3: {
            Delete(string);
        } break;
    }
    
    return 0;
}

void GetSubString(char string[]){
    int i = 0, j = 0;
    int startloc = 0;
    int len = 0;
    
    printf("Enter string: ");
    scanf("%s", string);
    printf("Enter startloc: ");
    scanf("%d", &startloc);
    printf("Enter len: ");
    scanf("%d", &len);
    
    for(i=startloc; i<startloc+len; i++){
        subs[j++] = string[i];
    }
    subs[j] = '\0';
    
    printf("substring: %s", subs);
}

void Insert(char string[]){
    int insertloc = 0;
    char tmp[100];
    int i = 0;
    int leni = 0, lens = 0, lent = 0;
    int j = 0, k = 0, m = 0;
    
    printf("Enter source string: ");
    scanf("%s", string);
    printf("Enter dest string: ");
    scanf("%s", inserts);
    printf("Enter insertloc: ");
    scanf("%d", &insertloc);
    
    leni = strlen(inserts);
    lens = strlen(string);
    for(i=insertloc; i<leni; i++){
        tmp[j++] = inserts[i]; //首先把位置后的转移到另一字符串
    }
    tmp[j] = '\0';
    
    lent = strlen(tmp);
    m = insertloc;
    for(i=0; i<=lens; i++){
        if(string[i]!='\0'){
            inserts[m++] = string[i];
        }
    } //把源字符插入到目标字符前
    
    for(i=0; i<lent; i++){
        inserts[m++] = tmp[i];
    } //把位置后的重新赋值给目标字符中
    inserts[m] = '\0';
    
    printf("result is: %s", inserts);
}

void Delete(char string[]){
    int deleteloc = 0;
    int deletelen = 0;
    int i = 0, j = 0;
    int len = 0;
    char tmp[100];
    
    printf("Enter string: ");
    scanf("%s", string);
    printf("Enter deleteloc: ");
    scanf("%d", &deleteloc);
    printf("Enter deletelen: ");
    scanf("%d", &deletelen);
    
    len = strlen(string);
    for(i=deleteloc+deletelen; i<len; i++){
        tmp[j++] = string[i];
    } //如果后面有余下的位，就存起来
    
    for(i=0; i<deletelen; i++){
        string[deleteloc+i] = tmp[i];
    }
    string[deletelen+i] = '\0';
    
    printf("string after delete: %s", string);
}
