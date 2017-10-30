#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include "queue.h"

#define MAXSIZE 20

using namespace std;

enum level{
    0, 1, 2
};

typedef struct{
    int no;
    level barber_wanted_level;
} Customer;

typedef struct{
    levl ba_level; 
    bool status; 
    //false-->available, true-->occupied now
} Barber;

void Init_customer(Customer &cu){
    cu.no = 0;
    cu.barber_wanted_level = 0;
}

void Init_barber(Barber &ba){
    ba.id = 0;
    ba.status = false;
}

void Change_ba_status(Barber &ba){
    if(ba.status) ba.status = false;
    else ba.status = true;
}


