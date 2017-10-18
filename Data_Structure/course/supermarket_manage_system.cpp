#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXSIZE 20

using namespace std;

typedef struct
{
    string name;
    int no;
    int amount;
    float price;
} Item;

typedef struct
{
    Item *list;
    int pre_class_no;
    int max_class_no;
} Shop;

void Init(Shop &S, int max_class_no)
{
    S.list = new Item[MAXSIZE];
    S.pre_class_no = 0;
    S.max_class_no = max_class_no;
}
//Init manage system

void Welcome()
{
    string name;
    cout << "enter ur name here: ";
    cin >> name;
    cout << "Hello, " << name;
    system("cls");

    cout << "Hello";

}

int main(void)
{
    Welcome();

    return 0;
}
