#include <stdio.h>
#include <string.h>
 
void GetSentence(char s[]);                              
void Split(char s[],char words[50][20],char count[]);    
void SelectionSort(char words[50][20]);
 
int main(void){
    char sen[100] ;
    char words[50][20],count[50];
    int i = 0;
    memset(count,'0',50);                   
    memset(words,' ',1000); //init

    GetSentence(sen);
    Split(sen,words,count);

    for(i=0; i<50; i++){
        words[i][0]=count[i];
    }

    SelectionSort(words);
    return 0;
}
 
void GetSentence(char s[]){
    printf("Enter your English sentence: ");
    gets(s);
}

void Split(char s[], char words[50][20], char count[]){
    int i = 0, j = 0, m = 0, n = 0, p = 0, q = 0;
    int sum = 0, flag = 0;
    int mark[100] = {0};

    //mark inited as 0, mark->1 while letter
    for(i=0; i<100; i++){
        if(s[i]>'A'&& s[i]<'Z') s[i] = s[i]- 'A' + 'a';
        if(s[i]>'a'&&s[i]<'z') mark[i+1] = 1;
        else mark[i+1] = 0;
    }
    mark[0] = 0;


    for(i=0,m=1; i<100&& j<50&& m<20;i++){
        if(mark[i]==0&& mark[i+1]==1) words[j][m++]=s[i];
        if(mark[i]==1&& mark[i+1]==1) words[j][m++]=s[i];
        if(mark[i]==1&& mark[i+1]==0){
            words[j][m++] = '\0';             
            m = 1;
            count[j++] = '1';
        }
        for(n=0; n<j-1; n++){
            for(q=1,sum=0; q<20; q++){
                flag = 1;
                if(words[n][q]==words[j-1][q]) flag = 0;
                sum+=flag;
            }
            if(sum==0){
                j--;
                count[n] = count[n]+1;
                count[j] = '0';
                for(p=0; p<20; p++)
                    words[j][p] = ' ';
            }
        }
    }
}
 
void SelectionSort(char words[50][20]){
    int i = 0 , j = 0, n = 0;
    char temp[20], max;

    for(i=0; i<50; i++){
        max=words[i][0];          
        for(j=i+1; j<50; j++){
            if(max<words[j][0]){
                max=words[j][0];              
            }
            if(max!=words[i][0]){
                for(n=0;n<20;n++){
                    temp[n]=words[i][n];
                }
                for(n=0;n<20;n++){
                    words[i][n]=words[j][n];
                }
                for(n=0;n<20;n++){
                    words[j][n]=temp[n];
                }
            }
        }
    }

    for(i=0;i<50;i++){
        if(words[i][0]!='0'){
            for(j=1;j<20;j++){
                if(words[i][j]!=' ')
                    printf("%-c",words[i][j]);
            }
            printf("(%c) ",words[i][0]);
            if(i%4==3)
                printf("\n");
        }
    }//output

    printf("\n");
}
