#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <ctime>
#include <vector>
#include <queue>

using namespace std;

class JOB{
    public:
        int no;
        int enter_time;
        int duration;
        int sys_time;
    //public:
        JOB(int n, int e, int d, int s);
};

JOB::JOB(int n, int e, int d, int s){
    no = n;
    enter_time = e;
    duration = d;
    sys_time = s;
}

vector<JOB> job_list;
int present_time = 0;
 
void Init(void){
    JOB tmp1(1, 800, 50, -1);
    job_list[0] = tmp1;
    present_time = job_list[0].enter_time;
    JOB tmp2(2, 815, 30, -1);
    job_list[1] = tmp2;
    JOB tmp3(3, 830, 25, -1);
    job_list[2] = tmp3;
    JOB tmp4(4, 835, 20, -1);
    job_list[3] = tmp4;
    JOB tmp5(5, 845, 15, -1);
    job_list[4] = tmp5;
    JOB tmp6(6, 900, 10, -1);
    job_list[5] = tmp6;
    JOB tmp7(7, 920, 5, -1);
    job_list[6] = tmp7;
}

int TimeProcess(int time);

void FIFO(void){
    for(int i=0; i<7; i++){
        if(job_list[i].enter_time<=present_time){
            job_list[i].sys_time = present_time;
            cout << job_list[i].no << '\t' << job_list[i].enter_time << '\t'
                 << job_list[i].duration << '\t' << job_list[i].sys_time << '\t'
                 << endl;
            present_time += job_list[i].duration;
            present_time = TimeProcess(present_time);
        }
        else{
            job_list[i].sys_time = job_list[i].enter_time;
            cout << job_list[i].no << '\t' << job_list[i].enter_time << '\t'
                << job_list[i].duration << '\t' << job_list[i].sys_time << '\t'
                << endl;
            present_time = TimeProcess(job_list[i].sys_time + job_list[i].duration);
        }
    }
    cout << endl;
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

int main(void){
    job_list.reserve(7);
    Init();

    FIFO();

    Init();
    return 0;
}
