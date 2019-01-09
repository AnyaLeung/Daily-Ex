#include <iostream>
#include <queue>

using namespace std;

queue<int> visiting_q;
int using_page[3] = {0};

void Init(void){
    using_page[0] = 1;
    using_page[1] = 2;
    using_page[2] = 3;

    visiting_q.push(4);
    visiting_q.push(1);
    visiting_q.push(2);
    visiting_q.push(5);
    visiting_q.push(1);
    visiting_q.push(2);
    visiting_q.push(3);
    visiting_q.push(4);
    visiting_q.push(5);

    cout << "[1]" << '\t' << "1" << endl;
    cout << "[2]" << '\t' << "1 2 " << endl;;
    cout << "[3]" << '\t' << "1 2 3 " << endl;
}

void Print(void){
    cout << using_page[0] << " " << using_page[1] << " ";
    cout << using_page[2] << "    ";
}

void FIFO(void){
    int pfcount = 3;

    while(!visiting_q.empty()){
        int tmp = visiting_q.front();
        if(using_page[0]!=tmp && using_page[1]!=tmp && using_page[2]!=tmp){
            pfcount++;
            cout << "[" << using_page[0] << "]";
            cout << '\b';
            using_page[0] = using_page[1];
            using_page[1] = using_page[2];
            using_page[2] = tmp;
        }
        cout << '\t';
        visiting_q.pop();
       Print();

       cout << endl;
    }

    cout << "page fault count: " << pfcount << endl;
    cout << "page fault rate: " << (double)pfcount / (double)12 << endl;
}

void LRU(void){
    int pfcount = 3;
    int times[6] = {0};
    times[1] += 1;
    times[2] += 1;
    times[3] += 1;

    while(!visiting_q.empty()){
        int tmp = visiting_q.front();
        times[tmp] += 1;
        if(using_page[0]!=tmp && using_page[1]!=tmp && using_page[2]!=tmp){
            pfcount++;
            int a = times[using_page[0]], b = times[using_page[1]];
            int c = times[using_page[2]];
            int min = (a > b ? (b > c ? c : b) : (a > c ? c : a)); //get min
            cout << "[" << using_page[min] << "]";
            cout << '\b';
            using_page[min] = tmp;
        }
        cout << '\t';
        visiting_q.pop();
        Print();

        cout << endl;
    }

    cout << "page fault count: " << pfcount << endl;
    cout << "page fault rate: " << (double)pfcount / (double)12 << endl;
}

int main(void){
    Init();
    FIFO();

    Init();
    LRU();

    return 0;
}
