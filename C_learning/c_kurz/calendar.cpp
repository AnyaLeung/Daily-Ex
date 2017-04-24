#include <iostream>
#include <iomanip>

using namespace std;

bool JudgeWhetherLeapYear(int year);
int GetDaysInEveryMonth(int year, int month, int day);
int CalFirstDayOfYear(int year);
void PrintMonthOfEveryLine(int a);
void PrintSuToSa();
void CalNextMonthFirstday(int *firstday, int *days);
void CorePrint(int month, int year, int day, int first_day_of_year);
 
int main(void) {
    int year = 2017;
    int month = 1;
    int day = 0;

    cout << "Enter the year you want here:" << endl;
    cin >> year;
    cout << endl;

    day = GetDaysInEveryMonth(year, month, day);

    int first_day_of_year = CalFirstDayOfYear(year);
        CorePrint(month, year, day, first_day_of_year);
        cout <<endl;

    return 0;
}

bool JudgeWhetherLeapYear(int year){
    if((year%4==0&&year%100!=0)||year%400==0)
        return true;
    else return false;
}

int GetDaysInEveryMonth(int year, int month, int day) {
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            day = 31; break;
        case 4: case 6: case 9: case 11:
            day = 30; break;
        case 2:{
                   if(JudgeWhetherLeapYear(year)) day=29;
                   else day=28;
               }      break;
    }
    return day;
} //every month

int CalFirstDayOfYear(int year) {
    int first_day_of_year = ((year-1)+(year-1)/4-(year-1)/100+(year-1)/400+1) % 7;
    return first_day_of_year;
}

void PrintMonthOfEveryLine(int a) {
    switch(a) {
        case 0:{
                   std::cout <<"January"<<"                         "<<"February"<<"                        "<<"March"<< std::endl;
               } break;

        case 1:{
                   std::cout <<"April"<<"                           "<<"May"<<"                             "<<"June"<< std::endl;
               } break;

        case 2:{
                   std::cout <<"July"<<"                            "<<"August"<<"                          "<<"September"<< std::endl;
               } break;

        case 3:{
                   std::cout <<"October"<<"                         "<<"November"<<"                        "<<"December"<< std::endl;
               } break;
    }
}

void PrintSuToSa() {
    std::cout <<"Su  Mo  Tu  We  Th  Fr  Sa";
    cout <<"\t";
    std::cout <<"Su  Mo  Tu  We  Th  Fr  Sa";
    cout <<"\t";
    std::cout <<"Su  Mo  Tu  We  Th  Fr  Sa\n";
}

void CalNextMonthFirstday(int *firstday, int *days) {
    for(int i=2; i<13; i++) {
        firstday[i] = (firstday[i-1]+days[i-1]) % 7;
    }
}

void CorePrint(int month, int year, int day, int first_day_of_year) {
    int days[13] = {0};
    int firstday[13] = {8}; //su, mo, tu......
    int count[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int line[4] = {1, 4, 7, 10}; //starting month of this line
    int line_count = 0;

    for(int i=1; i<13; i++) {
        days[i] = GetDaysInEveryMonth(year, i, day); 
    } //cal how many days of every month, save into array

    firstday[1] = first_day_of_year;
    CalNextMonthFirstday(firstday, days); 
    //get the firstday su, mo..., save into array
    
    cout << "Calendar of " << year << "\n" << endl;

    while(line_count<4){ 
        PrintMonthOfEveryLine(line_count); 
        PrintSuToSa();
        for(int m=line[line_count]; m<line[line_count]+3; m++){
            for(int j=0; j<4*firstday[m]; j++) {
                cout <<" "; //one fier whitespace
            }

            for(; count[m]+firstday[m]-1<7; count[m]++) {
                cout << setw(2) << count[m];
                cout << "  ";
            } 

            cout << "\t";
        }

        cout << endl;

        for(int m=line[line_count]; m<line[line_count]+3; m++){
            for(; count[m]<15-firstday[m]; count[m]++) {
                cout << setw(2) << count[m];
                cout << "  ";
            } 
            cout << "\t";
        }

        cout << endl;

        for(int m=line[line_count]; m<line[line_count]+3; m++){
            for(; count[m]<22-firstday[m]; count[m]++) {
                cout << setw(2) << count[m];
                cout << "  ";
            } 
            cout << "\t";
        }

        cout << endl;

        for(int m=line[line_count]; m<line[line_count]+3; m++){
            for(; count[m]<29-firstday[m]; count[m]++) {
                cout << setw(2) << count[m];
                cout << "  ";
            } 
            cout << "\t";
        }

        cout << endl;

        int movelast[13] = {0};
        for(int n=1; n<13; n++){
            movelast[n] = (36-firstday[n])<(days[n]+1)? (36-firstday[n]):(days[n]+1);
        }

        for(int m=line[line_count]; m<line[line_count]+3; m++){
            for(; count[m]<movelast[m]; count[m]++) {
                cout << setw(2) << count[m];
                cout << "  ";
            } 
            if(movelast[m]==days[m]+1) {
                for(int y=0; y<4*((7-firstday[m+1])%7); y++){
                    cout <<" ";
                }
            }//white space for the last (zwei) line
            cout << "\t";
        }

        cout << endl;


        for(int m=line[line_count]; m<line[line_count]+3; m++){
            if(movelast[m]==days[m]+1) {
                for(int y=0; y<4*7; y++){
                    cout <<" ";
                }
                cout << "\t";
            }

                if(movelast[m]!=days[m]+1) {
                    for(; count[m]<37-firstday[m]+days[m]-movelast[m]; count[m]++) {
                        cout << setw(2) << count[m];
                        cout << "  ";
                } 
                cout << endl;
            }
        }
        line_count++;
        cout << endl;
    }
    cout <<"Author:梁秋实";
}
