#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <ctime>
#include <vector>
#include <queue>

using namespace std;

/* globle variables definition */
enum status{
    ready = 1,
    waiting = 2,
    running = 3
};

class PROCESS{
    public:
        int id;
        int enter_time;
        enum status sta;
        int duration;
        int priority;
        int waiting_time; //not given
        int leaving_time;

        PROCESS(int ID, int d, int p, int et);
};

int ave_waiting_time = 0;
int present_time = 0;
vector<PROCESS> process_list;

PROCESS::PROCESS(int ID, int d, int p, int et){
    id = ID;
    sta = ready;
    duration = d;
    priority = p;
    waiting_time = -1;
    enter_time = et;
    leaving_time = 0;
}

/* function declarations */
/*
bool operator<(const JOB& a, const JOB& b) {
    return a.duration > b.duration;
}
*/

void Init(void){
    PROCESS tmp0(0, ready, 50, 0);
    process_list[0] = tmp0;
    PROCESS tmp1(1, waiting, 30, 3);
    process_list[1] = tmp1;
    PROCESS tmp2(2, running, 25, 4);
    process_list[2] = tmp2;
    PROCESS tmp3(3, waiting, 20, 1);
    process_list[3] = tmp3;
    PROCESS tmp4(4, running, 15, 0);
    process_list[4] = tmp4;
    PROCESS tmp5(5, waiting, 10, 1);
    process_list[5] = tmp5;
    PROCESS tmp6(6, waiting, 5, 2);
    process_list[6] = tmp6;
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
    cout << process_list[i].id + 1<< '\t' << process_list[i].enter_time << '\t'
        << process_list[i].status << 't' << process_list[i].duration << '\t' << process_list[i].sys_time << '\t'
        << process_list[i].end_time << '\t' << endl;
}

void FIFO(void){
    cout << '\t' << "FIFO ALGORITHM" << '\t' << endl;
    cout <<  "pid" << '\t' << "enter" << '\t' << "dura" 
         << '\t' << "sys" << '\t' << "end" << endl;
    for(int i=0; i<7; i++){
        if(job_list[i].enter_time<=present_time){
            job_list[i].sys_time = present_time; //begin exe
            job_list[i].visited = true;
            present_time += job_list[i].duration; //exe end
            present_time = TimeProcess(present_time);
            job_list[i].end_time = present_time;
            PrintRes(i);
        }
        else{
            job_list[i].sys_time = job_list[i].enter_time; //begin exe
            job_list[i].visited = true;
            present_time = TimeProcess(job_list[i].sys_time + job_list[i].duration);
            job_list[i].end_time = present_time;
            PrintRes(i);
            //exe end
        }
    }
    cout << endl;
}

bool JobFinish(){
    for(int i=0; i<7; i++){
        if(job_list[i].visited==false){
            return false;
        }
    }
    return true;
}

void SJFA(void){ //shortest job first algorithm
    cout << endl;
    cout << '\t' << "SJF ALGORITHM" << '\t' << endl;
    cout <<  "pid" << '\t' << "enter" << '\t' << "dura" 
         << '\t' << "sys" << '\t' << "end" << endl;
    priority_queue<JOB> waiting_q;

    while(true){
        for(int i=0; i<7; i++){
            if(job_list[i].enter_time<=present_time){
                if(!job_list[i].visited){
                    waiting_q.push(job_list[i]);
                    job_list[i].visited = true;
                    job_list[i].waiting = present_time - job_list[i].enter_time;
                }
            } //push into queue
        }

        if(!waiting_q.empty()){ //q not null
            int index = waiting_q.top().no;
            job_list[index].sys_time = present_time; //begin exe
            present_time += job_list[index].duration;
            present_time = TimeProcess(present_time); //exe end
            job_list[index].end_time = present_time;
            PrintRes(index);
            waiting_q.pop();
        }
        else{
            if(!JobFinish()){
                priority_queue<JOB> next_queue;
                for(int i=0; i<7; i++){
                    if(!job_list[i].visited){
                        next_queue.push(job_list[i]);
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

int CalculateHRRIndex(void){
   int max_index = -1;
   double maxRR = 0.0;

   for(int i=0; i<7; i++){
       if(job_list[i].visited==true && job_list[i].printed==false){
            if(job_list[i].iRR>maxRR ){
                max_index = i;
                maxRR = job_list[i].iRR;
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
    job_list[0].sys_time = present_time;
    present_time += job_list[0].duration;
    job_list[0].visited = true;
    job_list[0].end_time = present_time;
    PrintRes(0);

    while(true){
        for(int i=1; i<7; i++){
            if(job_list[i].enter_time<=present_time){
                if(!job_list[i].printed){
                    job_list[i].visited = true;
                    job_list[i].waiting = GetTimeInterval(present_time, job_list[i].enter_time);
                    job_list[i].iRR = (double)(job_list[i].waiting) / (double)(job_list[i].duration) + 1;
                }
            }
        }
        if(count<7){
            int index = CalculateHRRIndex(); //get HRR's index
            job_list[index].sys_time = present_time; //begin exe
            present_time += job_list[index].duration;
            present_time = TimeProcess(present_time); //exe end
            job_list[index].end_time = present_time;
            PrintRes(index);
            job_list[index].printed = true;
        }

        count ++;
        if(count==6) return ;
    }
}
function definitions end */

int main(void){
    process_list.reserve(7);
    Init();

    return 0;
}
