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
    //public:
        JOB(int n, int e, int d, int s, bool v);
};

JOB::JOB(int n, int e, int d, int s, bool v){
    no = n;
    enter_time = e;
    duration = d;
    sys_time = s;
    visited = v;
}

vector<JOB> job_list;
int present_time = 0;
/* globle varialbes definition end */

/* function declarations */
bool operator<(const JOB& a, const JOB& b) {
  return a.duration > b.duration;
}

void Init(void){
    JOB tmp1(1, 800, 50, -1, false);
    job_list[0] = tmp1;
    present_time = job_list[0].enter_time;
    JOB tmp2(2, 815, 30, -1, false);
    job_list[1] = tmp2;
    JOB tmp3(3, 830, 25, -1, false);
    job_list[2] = tmp3;
    JOB tmp4(4, 835, 20, -1, false);
    job_list[3] = tmp4;
    JOB tmp5(5, 845, 15, -1, false);
    job_list[4] = tmp5;
    JOB tmp6(6, 900, 10, -1, false);
    job_list[5] = tmp6;
    JOB tmp7(7, 920, 5, -1, false);
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
    cout << job_list[i].no << '\t' << job_list[i].enter_time << '\t'
        << job_list[i].duration << '\t' << job_list[i].sys_time << '\t'
        << endl;
}

void FIFO(void){
    for(int i=0; i<7; i++){
        if(job_list[i].enter_time<=present_time){
            job_list[i].sys_time = present_time; //begin exe
            job_list[i].visited = true;
            PrintRes(i);
            present_time += job_list[i].duration; //exe end
            present_time = TimeProcess(present_time);
        }
        else{
            job_list[i].sys_time = job_list[i].enter_time; //begin exe
            job_list[i].visited = true;
            PrintRes(i);
            present_time = TimeProcess(job_list[i].sys_time + job_list[i].duration);
            //exe end
        }
    }
    cout << endl;
}

void SJFA(void){ //shortest job first algorithm
    priority_queue<JOB> waiting_q;

    while(true){
        for(int i=0; i<7; i++){
            if(job_list[i].enter_time<=present_time){
                if(!job_list[i].visited){
                    waiting_q.push(job_list[i]);
                }
            } //push into queue
        }

        if(!waiting_q.empty()){ //q not null
            waiting_q.top().sys_time = present_time; //begin exe
            job_list[waiting_q.top().no].visited = true;
            PrintRes(waiting_q.top().no); 
            present_time += waiting_q.top().duration;
            present_time = TimeProcess(present_time); //exe end
            waiting_q.pop(); //remove from waitin' q
        }
        else{
            priority_queue<JOB> next_queue;
            for(int i=0; i<7; i++){
                if(!job_list[i].visited){
                    next_queue.push(job_list[i]);
                }
            }
            JOB next = next_queue.top();
            present_time = next.enter_time;
        }

        // all processed and exit
        bool all_visited = true;
        for(int i=0; i<7; i++){
            if(job_list[i].visited==false){
                all_visited = false;
            }
        }
        if(all_visited){
            return ;
        }
    }
}
/* function definitions end */

int main(void){
    job_list.reserve(7);

    Init();
    FIFO();

    Init();
    SJFA();

    return 0;
}
