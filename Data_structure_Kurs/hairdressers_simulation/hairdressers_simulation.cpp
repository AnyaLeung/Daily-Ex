#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <vector>
#include "hairdresser.h"
#define MAXSIZE 20

using namespace std;

//global variable
int customer_id  = 0;
int customer_count = 0;
int barber_id = 0;
queue<Customer> cu_1_waiting;
queue<Customer> cu_2_waiting;
queue<Customer> cu_3_waiting;

queue<Barber> ba_1_occupied;
queue<Barber> ba_2_occupied;
queue<Barber> ba_3_occupied;

queue<Barber> ba_1_free;
queue<Barber> ba_2_free;
queue<Barber> ba_3_free;
//global variable

enum level{
    level_one, level_two, level_three
}; //desc

/* functions */
void swap(Barber &a, Barber &b){
    Barber tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void Quick_sort_recursive(vector<Barber> a, int start, int end) {
    if (start >= end) return;
    int base = a[end].income;
    int left = start, right = end - 1;
    while (true) {
        while (a[left].income < base) ++left;
        while (a[right].income >= base) --right;
        if (left >= right) break;
        swap(a[left], a[right]);
    }
    if (a[left].income >= a[end].income) swap(a[left], a[end]);
    else ++left;
    Quick_sort_recursive(a, start, left - 1);
    Quick_sort_recursive(a, left + 1, end);
}

void Init_customer( Customer &cu, level wanted){
    cu.no = customer_id;
    cu.barber_wanted_level = wanted;

    customer_id ++;
} //init customer with level wanted

int Generate_customer_amount(){
    srand(time(0));
    int cu_amount = rand() % (40 - 60) + 10;
    cout << "The customers are coming..." << endl;
    cout << endl;

    sleep(2);

    return cu_amount;
}

void Init_customer_list(Customer *cu_list, int cu_amount){
    Customer *p;
    p = cu_list;
    //p = new Customer[cu_amount];

    for(int i=0; i<cu_amount; i++){
        level level_wanted;
        int lw = rand() % (3 - 0);

        switch(lw){
            case 0: level_wanted = level_one; break;
            case 1: level_wanted = level_two; break;
            case 2: level_wanted = level_three; break;
        }

        Init_customer(p[i], level_wanted);
    }
    cu_list++;
}//generate customer list with ba

void Init_barber(Barber &ba, level ba_level){
    ba.ba_level =  ba_level;
    ba.status = false;
    ba.no = barber_id;
    ba.income = 0;

    barber_id ++;
} //init with par level

void Init_barber_list(Barber *ba_list, level ba_level, int amount){
    Barber *p;
    p = ba_list;

    for(int i=0; i<amount; i++){
        Init_barber(p[i], ba_level);
    }
}

void Allo_to_ba(Customer cu, Barber* ba_list_level_one, Barber* ba_list_level_two, Barber* ba_list_level_three) {
    switch (cu.barber_wanted_level) {
        case level_one :
            if (ba_1_free.empty()) { //not available
                cu_1_waiting.push(cu);
            } else {
                if(cu_1_waiting.size()) {
                    cu_1_waiting.push(cu);
                }
                else {
                    Barber tmp;
                    tmp = ba_1_free.front();
                    cout << "                        Level ONE barber No. " << tmp.no << " is now serving." << endl;
                    cout << endl;
                    ba_list_level_one[tmp.no].income += 90;
                    ba_1_occupied.push(tmp);
                    ba_1_free.pop();
                }
            }
            break;
        case level_two :
            if (ba_2_free.empty()) {
                cu_2_waiting.push(cu);
            } else {
                if(cu_2_waiting.size()) {
                    cu_2_waiting.push(cu);
                }
                else{
                    Barber tmp;
                    tmp = ba_2_free.front();
                    cout << "                        Level TWO barber No. " << tmp.no << " is now serving." << endl;
                    cout << endl;
                    ba_list_level_two[tmp.no-2].income += 60;
                    ba_2_occupied.push(tmp);
                    ba_2_free.pop();
                }
            }
            break;
        case level_three :
            if (ba_3_free.empty()) {
                cu_3_waiting.push(cu);
            } else {
                if (cu_3_waiting.size()) {
                    cu_3_waiting.push(cu);
                }
                else {
                    Barber tmp;
                    tmp = ba_3_free.front();
                    cout << "                        Level THREE barber No. " << tmp.no << " is now serving." << endl;
                    cout << endl;
                    ba_list_level_three[tmp.no-5].income += 30;
                    ba_3_occupied.push(tmp);
                    ba_3_free.pop();
                }
            }
            break;
    }
}

void Load_cu(Customer* cu_list, Barber* ba_list_level_one, Barber* ba_list_level_two, Barber* ba_list_level_three){
    while(customer_count<customer_id) {
        if(ba_1_free.empty()){
            Barber tmp;
            tmp = ba_1_occupied.front();
            ba_1_free.push(tmp);
            ba_1_occupied.pop();
        } //serving
        if(ba_2_free.empty()){
            Barber tmp;
            tmp = ba_2_occupied.front();
            ba_2_free.push(tmp);
            ba_2_occupied.pop();
        } //serving
        if(ba_3_free.empty()){
            Barber tmp;
            tmp = ba_3_occupied.front();
            ba_3_free.push(tmp);
            ba_3_occupied.pop();
        } //serving

         sleep(1);
        Allo_to_ba(cu_list[customer_count], ba_list_level_one, ba_list_level_two, ba_list_level_three);
        customer_count++; //richtig
    }
}

void Welcome_and_open(){
    char open;
    system("clear");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "              **************************************************************" << endl;
    cout << "              *                                                            *" << endl;
    cout << "              *               Welcome to our barbershop!                   *"<< endl;
    cout << "              *                                                            *" << endl;
    cout << "              **************************************************************" << endl;
    cout << endl;
    cout << "                          Press [S] to start business: " ;
    cin >> open;
    if(open=='S'){
        system("clear");
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "              **************************************************************" << endl;
    cout << "              *                                                            *" << endl;
    cout << "              *   Our barbershop is running now, customers are coming...   *" << endl;
    cout << "              *                                                            *" << endl;
    cout << "              **************************************************************" << endl;
    cout << endl;

}

void Summary(Barber* ba_list_level_one, Barber* ba_list_level_two, Barber* ba_list_level_three, vector<Barber> a){
    int turnover_today = 0;
    char c;
    for(int i=0; i<2; i++){
        turnover_today += ba_list_level_one[i].income;
    }
    for(int i=0; i<3; i++){
        turnover_today += ba_list_level_two[i].income;
    }
    for(int i=0; i<5; i++){
        turnover_today += ba_list_level_three[i].income;
    }

    system("clear");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "              **************************************************************" << endl;
    cout << "                   Time to close, press [S] to see total turnover: ";
    cin >> c;
    cout << endl;
    if(c=='S'){
        cout << "                   Got " << turnover_today << " today!" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    cout << "              **************************************************************" << endl;
    cout << "                    Press [D] to see details about how much barbers earn: ";
    cin >> c;
    if(c=='D'){
        Quick_sort_recursive(a, 0, a.size()-1);
    }
    cout << endl;
    cout << endl;
    for(int i=0; i<10; i++){
        cout << "                            Barber No." << a[i].no << " earns " << a[i].income << " today." << endl;
    }
    cout << endl;
    cout << "                    Press [E] to exit: " ;
    cin >> c;
    cout << endl;
    if(c=='E') exit(0);
}

int main(void){
    int cu_amount = Generate_customer_amount();
    cout << cu_amount << endl;
    Customer *cu_list;
    cu_list = new Customer[cu_amount];
    Init_customer_list(cu_list, cu_amount);
    //init customer list with level wanted

    Barber *ba_list_level_one;
    ba_list_level_one = new Barber[2]; //no: 0 1
    Barber *ba_list_level_two;
    ba_list_level_two = new Barber[3]; //no: 2 3 4
    Barber *ba_list_level_three;
    ba_list_level_three = new Barber[5]; //no: 5 6 7 8 9
    Init_barber_list(ba_list_level_one, level_one, 2);
    Init_barber_list(ba_list_level_two, level_two, 3);
    Init_barber_list(ba_list_level_three, level_three, 5);
    //init barber of different level, set all status to false

    for(int i=0; i<2; i++) ba_1_free.push(ba_list_level_one[i]);
    for(int i=0; i<3; i++) ba_2_free.push(ba_list_level_two[i]);
    for(int i=0; i<5; i++) ba_3_free.push(ba_list_level_three[i]);
    // init queue, push all ba to free queue

    Welcome_and_open();
    Load_cu(cu_list, ba_list_level_one, ba_list_level_two, ba_list_level_three);

    vector<Barber> a;

    for(int i=0; i<2; i++) a.push_back(ba_list_level_one[i]);
    for(int i=0; i<3; i++) a.push_back(ba_list_level_two[i]);
    for(int i=0; i<5; i++) a.push_back(ba_list_level_three[i]);

    Summary(ba_list_level_one, ba_list_level_two, ba_list_level_three, a);

    return 0;
}
