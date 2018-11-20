#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <ctime>
#include <vector>
#include <queue>

using namespace std;

/* globle variables definition */
class JOB{
    public:
        int no;
        int enter_time;
        int duration;
        int sys_time;
        bool visited;
        int waiting;
        bool printed;
        double iRR;
        int end_time;
    //public:
        JOB(int n, int e, int d);
};

JOB::JOB(int n, int e, int d){
    no = n;
    enter_time = e;
    duration = d;
    sys_time = -1;
    end_time = 0;
    visited = false;
    waiting = 0;
    iRR = -1;
    printed = false;
}

vector<JOB> job_list;
int present_time = 0;
/* globle varialbes definition end */

/* function declarations */
bool operator<(const JOB& a, const JOB& b) {
    return a.duration > b.duration;
}

void Init(void){
    JOB tmp1(0, 800, 50);
    job_list[0] = tmp1;
    present_time = job_list[0].enter_time;
    JOB tmp2(1, 815, 30);
    job_list[1] = tmp2;
    JOB tmp3(2, 830, 25);
    job_list[2] = tmp3;
    JOB tmp4(3, 835, 20);
    job_list[3] = tmp4;
    JOB tmp5(4, 845, 15);
    job_list[4] = tmp5;
    JOB tmp6(5, 900, 10);
    job_list[5] = tmp6;
    JOB tmp7(6, 920, 5);
    job_list[6] = tmp7;
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
    cout << job_list[i].no + 1<< '\t' << job_list[i].enter_time << '\t'
        << job_list[i].duration << '\t' << job_list[i].sys_time << '\t'
        << job_list[i].end_time << '\t' << endl;
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
/* function definitions end */

int main(void){
    job_list.reserve(7);

    Init();
    FIFO();

    Init();
    SJFA();

    Init();
    HRRN();
    return 0;
}
