#include <stdio.h>
#include <string.h>

int count[20];
int word_count = 0;

void SplitIntoWords(char sen[], char Words[20][20]);
char JudgeAndToLowerCase(char a);

int main(void){
    char sen[2000];
    char Words[20][20];
    int i = 0;
    printf("Enter a sentence in English: ");
    gets(sen);

    SplitIntoWords(sen, Words);

    return 0;
}

void SplitIntoWords(char sen[], char Words[20][20]){
    char tmp;
    char pause[20];
    int i = 0, j = 0;
    bool flag = 1;
    char *pnew = sen;

    while(*pnew!='\0'){
        tmp = JudgeAndToLowerCase(*pnew);
        printf("%c", tmp);

        if(!tmp){ //如果是空的，代表不是字母，这个单词就结束了
            pause[i]  = '\0';
//            printf("%s\n", pause);
            for(j=0; j<word_count; j++){
                if(Words[j]==pause){
                    count[j]++;
                    flag = 0;
                }
            } //看是否有和某一个已有单词一样
            if(flag){
                strcpy(Words[word_count], pause);
                word_count++;
            }
            memset(pause,'\0',20);  
        }

        else{
            pause[i] = tmp;
            i++;
        }

      //  printf("pause: %s\n", pause);
        flag = 1;
        pnew++;
    }
    
}

char JudgeAndToLowerCase(char a){
    if(a>='A'&&a<='Z'){
        a -= 'A';
        a += 'a';
        return a;
    }
    if(a>='a'&&a<='z') return a;
    else return 0;
}
