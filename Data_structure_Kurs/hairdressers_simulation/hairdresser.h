#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct{
    int no;
    int barber_wanted_level;
} Customer;

typedef struct{
    int ba_level; 
    bool status; 
    //false-->available, true-->occupied now
} Barber;
