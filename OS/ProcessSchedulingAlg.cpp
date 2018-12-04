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
        int remaining_time;
        bool executed;

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
    remaining_time = duration;
    executed = false;
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

int GetTimeInterval(int t1, int t2){
    if((t1-t2)<60){
        return t1 - t2;
    }
    return t1 - t2 - 40;
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
    cout << '\t' << "PBS ALGORITHM" << '\t' << endl;
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
                    process_list[i].waiting = GetTimeInterval(present_time, process_list[i].enter_time);
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

void NextRound(void){
    present_time += 1;
}

void RR(void){ //Round-Robin
    //supposed every time slice is 1 min 
    cout << endl;
    cout << '\t' << "RR ALGORITHM" << '\t' << endl;
    cout <<  "pid" << '\t' << "enter" << '\t' << "prori"
         << '\t' << "dura" << '\t' << "sys" 
         << '\t' << "end" << endl;
    int count = 0;
    queue<PROCESS> waiting_q;

    while(true){
        for(int i=0; i<7; i++){
            if(process_list[i].enter_time<=present_time){
                //cout << "p:" << present_time;
                //cout << " " << i << " " << endl;
                if(!process_list[i].visited){
                    waiting_q.push(process_list[i]);
                    process_list[i].visited = true;
                    process_list[i].waiting = GetTimeInterval(present_time, process_list[i].enter_time);
                }
            } //push into queue
        }
        if(!waiting_q.empty()){
            NextRound();
            int index = waiting_q.front().no;
            process_list[index].sys_time = present_time;
            process_list[index].remaining_time -= 1;
            if(process_list[index].remaining_time==0){
                process_list[index].end_time = present_time;
                PrintRes(index);
                waiting_q.pop();
                count ++;
            }
            else{
                waiting_q.pop();
                waiting_q.push(process_list[index]);
            }
        }
        else{
            if(count==7){
                cout << endl;
                return ;
            }
        }
    }
}

void HSA(void){ //hierarchical scheduling
    cout << endl;
    cout << '\t' << "HSA ALGORITHM" << '\t' << endl;
    cout <<  "pid" << '\t' << "enter" << '\t' << "prori"
        << '\t' << "dura" << '\t' << "sys" 
        << '\t' << "end" << endl;
    queue<PROCESS> first_level; //highest precedence, least time, 10 time slice
    queue<PROCESS> second_level; //15 time slice
    int count = 0;
    int first_level_count = 0, second_level_count = 0;

    while(true){
        for(int i=0; i<7; i++){
            if(process_list[i].enter_time<=present_time){
                if(!process_list[i].visited){
                    first_level.push(process_list[i]); //put into queue end
                    process_list[i].visited = true;
                    process_list[i].waiting = GetTimeInterval(present_time, process_list[i].enter_time);
                }
            }
        }

        if(!first_level.empty()){
            NextRound();
            int index = first_level.front().no;
            process_list[index].sys_time = present_time;
            process_list[index].remaining_time -= 1;
            first_level_count++;
            if(process_list[index].remaining_time==0){
                process_list[index].end_time = present_time;
                PrintRes(index);
                first_level.pop();
                count ++;
            }
            else{
                if(first_level_count>=15){
                    while(!first_level.empty()){
                        int i = first_level.front().no;
                        first_level.pop();
                        second_level.push(process_list[index]);
                    }
                }
                else{
                    first_level.pop();
                    first_level.push(process_list[index]);
                }
            }
        }
        if(!second_level.empty()){
            NextRound();
            int index = second_level.front().no;
            process_list[index].sys_time = present_time;
            process_list[index].remaining_time -= 1;
            if(process_list[index].remaining_time==0){
                process_list[index].end_time = present_time;
                PrintRes(index);
                second_level.pop();
                count ++; 
            }
            else{
                second_level.pop();
                second_level.push(process_list[index]);
            }
        }
        else{
            if(count==7){
                cout << endl;
                return ;
            }
        }
    }
}
/* function definitions end */

int main(void){
    process_list.reserve(7);

    Init();
    FIFO();

    Init();
    PBS();

    Init();
    RR();
     
    Init();
    HSA();
    return 0;
}
