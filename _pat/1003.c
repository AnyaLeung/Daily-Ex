#没写出来
void print_no(int line_no){
    print("no");
}

#include <stdio.h>

int main(void){
    int line_amount = 0;
    char store_char[10][100]; //store every string
    int flag = 0;
    int line_no = 0;
    int count_char = 0;
    int result[10] = {10}; //result for every line, yes or no
    char temp;

    scanf("%d", &input_amount);

    scanf("%c", &temp);
    store_char[line_no][count_char] = temp;
    count_char++;

    while(line_no!=line_amount-1){
        do{
            scanf("%c", &temp);
            store_char[line_no][count_char] = temp;
            count_char++;
        }while(temp!='\n')
        line_no++; 
    } //store reversely

    while(line_no!=-1){
        if( !=' '&&!='A'&&!='T'){
            print_no(line_no);
            line_no--;
        }
        else{
            if(='T'){
                if(='A'){
                    if(='A'||='P') 
                }
                
            }
            else print_no(line_no);
        }
    }

    return 0;
}
