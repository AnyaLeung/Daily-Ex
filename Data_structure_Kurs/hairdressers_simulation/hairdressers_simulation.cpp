#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include "hairdresser.h"

#define MAXSIZE 20

using namespace std;

//global variable
int customer_id  = 0;
int customer_count = 0;
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
void Init_customer( Customer &cu, level wanted){
    cu.no = customer_id;
    cu.barber_wanted_level = wanted;

    customer_id ++;
} //init customer with level wanted

int Generate_customer_amount(){
    srand(time(0));
    int cu_amount = rand() % (100 - 20) + 10;
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

void Load_cu(Customer* cu_list){
    sleep(1);
    cout << "The num " << cu_list[customer_count].no + 1 << " customer comes." << endl;
    cout << "This customer wants level " << cu_list[customer_count].barber_wanted_level << " barber." << endl;
    Allo_to_ba(cu_list[customer_count]);
//??
    customer_count++;
}

void Init_barber(Barber &ba, level ba_level){
    ba.ba_level =  ba_level;
    ba.status = false;
} //init with par level

void Change_ba_status(Barber &ba){
    if(ba.status) ba.status = false;
    else ba.status = true;
} //after serving

void Allo_to_ba(Customer cu){
    switch(cu.barber_wanted_level) {
        case level_one :
            if(!ba_1_free.empty()){
                cout << "no " << cu.no + 1 << "enqueue. " << endl;
                cu_1_waiting.push(cu);
            }
            else{
                cout << "serving" << cu.no + 1 << endl;
                ba_1_free.front;
                ba_1_free.pop();
            }
                break;
        case level_two :
            if(!ba_2_free.empty()){
                cout << "no " << cu.no + 1 << "enqueue. " << endl;
                cu_2_waiting.push(cu);
            }
            else{
                cout << "serving" << cu.no + 1 << endl;
                ba_2_free.front;
                ba_2_free.pop();
                break;
        case level_three :
            if(!ba_3_free.empty()){
                cout << "no " << cu.no + 1 << "enqueue. " << endl;
                cu_3_waiting.push(cu);
            }
            else{
                cout << "serving" << cu.no + 1 << endl;
                ba_3_free.front;
                ba_3_free.pop();
                break;
    }
}

bool Inquire_ba_empty(level cu_level){

}

void Init_barber_list(Barber *ba_list, level ba_level){
    Barber *p;
    p = ba_list;

    for(int i=0; i<5; i++){
        Init_barber(p[i], ba_level);
   }
}

int Return_customer_wanted_level(Customer *cu_list, int i){
    return cu_list[i].barber_wanted_level;
}

void Welcome_and_open(){
    char open;
    cout << "*********************************" << endl;
    cout << "Welcome to our barbershop!" << endl;
    cout << "*********************************" << endl;
    cout << "Press [S] to start business: " ;
    cin >> open;
    if(open=='S'){
        system("clear");
    }
    cout << "**********************************************************" << endl;
    cout << "Our barbershop is running now, the customers are coming..." << endl;
    cout << "**********************************************************" << endl;

}
//load customer

/*
void Allo_to_level_one(Customer *cu_list, Barber *ba_list_level_one){
    for(int i=0; i<5; i++){
        if(!ba_list_level_one[i].status){
            cout << "Now serving " customer.id << endl;
            sleep(3);
            
        }//available
    }
}
 */
/* functions */

int main(void){
    int cu_amount = Generate_customer_amount();
    Customer *cu_list;
    cu_list = new Customer[cu_amount];
    Init_customer_list(cu_list, cu_amount);
    //init customer list with level wanted

    Barber *ba_list_level_one;
    ba_list_level_one = new Barber[2];
    Barber *ba_list_level_two;
    ba_list_level_two = new Barber[5];
    Barber *ba_list_level_three;
    ba_list_level_three = new Barber[5];
    Init_barber_list(ba_list_level_one, level_one);
    Init_barber_list(ba_list_level_two, level_two);
    Init_barber_list(ba_list_level_three, level_three);
    //init barber of different level, set all status to false

    for(int i=0; i<5; i++) ba_1_free.push(ba_list_level_one[i]);
    for(int i=0; i<5; i++) ba_2_free.push(ba_list_level_two[i]);
    for(int i=0; i<5; i++) ba_3_free.push(ba_list_level_three[i]);
    // init queue, place all ba to free queue

    Load_cu();

    return 0;
}