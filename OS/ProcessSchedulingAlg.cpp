#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <ctime>
#include <vector>
#include <queue>

using namespace std;

/* globle variables definition */
class PROCESS{
    public:
        int no;
        int enter_time;
        int duration;
        int sys_time;
        int waiting;
        int prority;
        int end_time;
        bool visited;
        //int waiting;
        //bool printed;
        //double iRR;

    //public:
        PROCESS(int n, int e, int d, int p);
};

PROCESS::PROCESS(int n, int e, int d, int p){
    no = n;
    enter_time = e;
    duration = d;
    sys_time = -1;
    end_time = 0;
    waiting = 0;
    prority = p;
    visited = false;
    //iRR = -1;
    //printed = false;
}

vector<PROCESS> process_list;
int present_time = 0;
/* globle varialbes definition end */

/* function declarations */
bool operator<(const PROCESS& a, const PROCESS& b) {
    return a.prority > b.prority;
}

void Init(void){
    PROCESS tmp1(0, 800, 50, 0);
    process_list[0] = tmp1;
    PROCESS tmp2(1, 815, 30, 1);
    process_list[1] = tmp2;
    PROCESS tmp3(2, 830, 25, 3);
    process_list[2] = tmp3;
    PROCESS tmp4(3, 835, 20, 2);
    process_list[3] = tmp4;
    PROCESS tmp5(4, 845, 15, 1);
    process_list[4] = tmp5;
    PROCESS tmp6(5, 900, 10, 0);
    process_list[5] = tmp6;
    PROCESS tmp7(6, 920, 5, 1);
    process_list[6] = tmp7;

    present_time = process_list[0].enter_time;
}

int TimeProcess(int time){
    int res = 0;
    int Last2Digit = time % 100;

    if(Last2Digit>=60){
        res += Last2Digit - 60;
        res += (time / 100 + 1) * 100;
    }
    else{
        return time;
    }
    return res;
}

void PrintRes(int i){
    cout << process_list[i].no + 1<< '\t' << process_list[i].enter_time << '\t'
        << process_list[i].prority << '\t' << process_list[i].duration << '\t' 
        << process_list[i].sys_time << '\t' << process_list[i].end_time << '\t' 
        << endl;
}

void Execute(int i){
    process_list[i].sys_time = present_time;
    present_time +=  process_list[i].duration;
    present_time = TimeProcess(present_time);
    process_list[i].end_time = present_time;
    PrintRes(i);
}

bool JobFinish(){
    for(int i=0; i<7; i++){
        if(process_list[i].visited==false){
            return false;
        }
    }
    return true;
}

void FIFO(void){
    cout << '\t' << "FIFO ALGORITHM" << '\t' << endl;
    cout <<  "pid" << '\t' << "enter" << '\t' << "prori" 
         << '\t' << "dura" << '\t' << "sys" << '\t' << "end" 
         << endl;

    for(int i=0; i<7; i++){
        if(process_list[i].enter_time<=present_time){
            Execute(i);
        }
        else{
            present_time = TimeProcess(process_list[i].sys_time + process_list[i].duration);
            Execute(i);
        }
    }
    cout << endl;
}

void PBS(void){ //prority based scheduling
    cout << endl;
    cout << '\t' << "SJF ALGORITHM" << '\t' << endl;
    cout <<  "pid" << '\t' << "enter" << '\t' << "prori"
         << '\t' << "dura" << '\t' << "sys" 
         << '\t' << "end" << endl;
    priority_queue<PROCESS> waiting_q;

    while(true){
        for(int i=0; i<7; i++){
            if(process_list[i].enter_time<=present_time){
                if(!process_list[i].visited){
                    waiting_q.push(process_list[i]);
                    process_list[i].visited = true;
                    process_list[i].waiting = present_time - process_list[i].enter_time;
                }
            } //push into queue
        }

        if(!waiting_q.empty()){ //q not null
            int index = waiting_q.top().no;
            Execute(index);
            waiting_q.pop();
        }
        else{
            if(!JobFinish()){
                priority_queue<PROCESS> next_queue;
                for(int i=0; i<7; i++){
                    if(!process_list[i].visited){
                        next_queue.push(process_list[i]);
                    }
                }
                present_time = next_queue.top().enter_time;
            }
            else{
                cout << endl;
                return ;
            }
        }
    }
}

void SJFA(void){ //shortest job first algorithm
    cout << endl;
    cout << '\t' << "SJF ALGORITHM" << '\t' << endl;
    cout <<  "pid" << '\t' << "enter" << '\t' << "dura" 
         << '\t' << "sys" << '\t' << "end" << endl;
    priority_queue<PROCESS> waiting_q;

    while(true){
        for(int i=0; i<7; i++){
            if(process_list[i].enter_time<=present_time){
                if(!process_list[i].visited){
                    waiting_q.push(process_list[i]);
                    process_list[i].visited = true;
                    process_list[i].waiting = present_time - process_list[i].enter_time;
                }
            } //push into queue
        }

        if(!waiting_q.empty()){ //q not null
            int index = waiting_q.top().no;
            process_list[index].sys_time = present_time; //begin exe
            present_time += process_list[index].duration;
            present_time = TimeProcess(present_time); //exe end
            process_list[index].end_time = present_time;
            PrintRes(index);
            waiting_q.pop();
        }
        else{
            if(!JobFinish()){
                priority_queue<PROCESS> next_queue;
                for(int i=0; i<7; i++){
                    if(!process_list[i].visited){
                        next_queue.push(process_list[i]);
                    }
                }
                present_time = next_queue.top().enter_time;
            }
            else{
                cout << endl;
                return ;
            }
        }
    }
}

/*
int CalculateHRRIndex(void){
   int max_index = -1;
   double maxRR = 0.0;

   for(int i=0; i<7; i++){
       if(process_list[i].visited==true && process_list[i].printed==false){
            if(process_list[i].iRR>maxRR ){
                max_index = i;
                maxRR = process_list[i].iRR;
            }
       }
   }
   return max_index;
}

int GetTimeInterval(int t1, int t2){
    if((t1-t2)<60){
        return t1 - t2;
    }
    return t1 - t2 - 40;
}

void HRRN(void){ //highest response ratio next algorithm
    cout << endl;
    cout << '\t' << "HRRN ALGORITHM" << '\t' << endl;
    cout <<  "pid" << '\t' << "enter" << '\t' << "dura" 
         << '\t' << "sys" << '\t' << "end" << endl;
    int count = 0;

    //exe job 0
    process_list[0].sys_time = present_time;
    present_time += process_list[0].duration;
    process_list[0].visited = true;
    process_list[0].end_time = present_time;
    PrintRes(0);

    while(true){
        for(int i=1; i<7; i++){
            if(process_list[i].enter_time<=present_time){
                if(!process_list[i].printed){
                    process_list[i].visited = true;
                    process_list[i].waiting = GetTimeInterval(present_time, process_list[i].enter_time);
                    process_list[i].iRR = (double)(process_list[i].waiting) / (double)(process_list[i].duration) + 1;
                }
            }
        }
        if(count<7){
            int index = CalculateHRRIndex(); //get HRR's index
            process_list[index].sys_time = present_time; //begin exe
            present_time += process_list[index].duration;
            present_time = TimeProcess(present_time); //exe end
            process_list[index].end_time = present_time;
            PrintRes(index);
            process_list[index].printed = true;
        }

        count ++;
        if(count==6) return ;
    }
}
 function definitions end */

int main(void){
    process_list.reserve(7);

    Init();
    FIFO();

    Init();
    PBS();

    /*
    Init();
    HRRN();
    */
    return 0;
}
