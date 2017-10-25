#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fstream>

#define MAXSIZE 20

using namespace std;


//struct declaration

typedef struct
{
    string name;
    int iid;
    int amount;
    int price;
} Item;

typedef struct
{
    Item *list;
    int pre_class_no;
    int max_class_no;
} Supermarket;

/*
 typedef struct
 {
 Item *list;
 Item best_sell_today;
 int total_today;
 } today;
 */

typedef struct
{
    Item *goods;
    int trade_id; //交易号
    int cashier_id; //收银员号
    int mid; //cash machine id
    int time; //trade time
    int paid_amount; //实收金额
    int change_amount; //找零金额
    int alipay; //0-->with cash, else with alipay
    int VIP_no; //0-->nicht VIP, else is VIP
    int VIP_points; //0-->nicht, else is points
    
} Bill;

//struct declaration end


int bill_count = 1;
Bill bill[4];

//function prototype

///*
void Welcome(Supermarket su);
void Init(Supermarket &S);
void Init_good(Item &g1, string name, int iid, float price);
void Read_bill(Supermarket su);
void Show_all_items(Supermarket su);
void Load_goods(Supermarket &S);
//void Show_sale_today();
void Search_item();
void Show_VIP();
void Show_today();
void Read_file_by_word(Supermarket &su, Bill &b);
void Entrance(Supermarket su);
bool Is_good(char tmp, Supermarket su);
void Bubble_sort(Supermarket &su);
//*/

//function prototype end


//functions below

void Init(Supermarket &S)
{
    S.list = new Item[MAXSIZE];
    S.pre_class_no = 0;
    S.max_class_no = MAXSIZE;
}
//Init manage system

void Init_good(Item &g1, string name, int iid, float price)
{
    g1.name = name;
    g1.iid = iid;
    g1.amount = 0;
    g1.price = price;
}

bool Is_good(char tmp, Supermarket su)
{

    //char tmp = item_name[0];
    //cout << tmp;


    for(int i=0; i<20; i++)
    {
        if(tmp==su.list[i].name[0])
        {
            cout << "ok";
            return true;
        }
        cout << su.list[i].name[0] << " ";
        //
    }
    
    return false;
    
}

//ok
void Copy_good(Item g1, Item &g2) //g1-->g2
{
    Init_good(g2, g1.name, g1.iid, g1.price);
}
//descending order

void Bubble_sort(Supermarket &su)
{
    Item tmp;

    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20-i; j++)
        {
            if(su.list[j].amount<su.list[j+1].amount)
                Copy_good(su.list[i], tmp);
                Copy_good(su.list[i+1], su.list[i]);
                Copy_good(tmp, su.list[i+1]);
        }
    }
    
    for(int i=0; i<20; i++)
    {
        cout << su.list[i].name << endl;
    }
}

//ok
bool Whether_Chinese(string s)
{
    if(((s[0]>='0') && (s[0]<='9')) || ((s[0]>='A') && (s[0]<='z')))
    //if(s[0]>='0' && s[0]<='9')
        return false;

    //if(string[0]>='A' && string string[0])
    //    if(string[0])
    //return false;
    //nicht Chinese

    return true;
}

int Return_good_id(string name, Supermarket su)
{

    for(int i=0; i<20; i++)
    {
        if(name==su.list[i].name)
        {
            return i;
        }
    }
    return 0;

}

/*
bool Judge(string line)
{
    string ne= "###";
    if(line==ne) return true;
    return false;
}
*/

float Find_no_this_line(string line)
{
    //char *p;
    float res[8] = {0};
    int i = 0, digit = 0;
    float re = 0;
    int m = 0;
    int lcount = 1;

    //p = new char[256];
    //p = line;

    while(!(line[i]>='0' && line[i]<='9'))
    {
        i++;
    }
    
    while(line[i]!='\0')
    {
        //if(line[i]=='-') ;
        if(line[i]=='.')
        {
            res[digit++] = int(line[i+1]) - '0';
        }

        else
        {
            res[digit++] = int(line[i]) - '0';
        }

        
        i++;
    }

    for(int j=0; j<digit; j++)
    {
       re *= 10;
       re += res[m++];
    }
    
    return re;
}

void Init_bill(Bill &b)
{

    b.goods = new Item[20];
    b.trade_id = 0;
    b.cashier_id = 0;
    b.mid = 0;
    b.time = 0;
    b.paid_amount = 0;
    b.change_amount = 0;
    b.alipay = 0;
    b.VIP_no = 0;
    b.VIP_points = 0;

}

void Read_file_by_word(Supermarket &su, Bill &b)
{    
    system("clear");
    
    Init_bill(b);

    cout << endl;
    cout << endl;
    cout << endl;
    
    cout << "          ***********************************************************";
    cout << endl;
    cout << "                                    读取账单 ";
    cout << endl;
    cout << "          ***********************************************************";
    cout << endl;
    cout << endl;
 
    string filename;

    cout << "              Enter the bill name you want to load into system: ";
    cout << endl;
    cout << "              ";

    cin >> filename;
    while(filename!="bill1.txt" && filename!="bill2.txt" && filename!="bill3.txt" && filename!="bill4.txt")
    {
        cout << "Wrong bill name! Enter again!";
        cin >> filename;
    }
    cout << endl;
    cout << endl;

    int count = 0;

    int res = 0;

    ifstream fin(filename);
    //cout << "filename" << filename << "   " << endl;
    string s;

    while( fin >> s )
    {
        if(Whether_Chinese(s)) //good namej
        {
            int good_index = Return_good_id(s, su);

            fin >> s; //read next word

            b.goods[count++] = su.list[good_index];
            su.list[good_index].amount += int(s[0]);
            su.list[good_index].amount -= '0';

            cout << endl;
        }
        //read goods and change amount status in this function

        if(s[0]=='t' && s[1]=='r') 
        {
            //cout << "ok";
            fin >> s;
            res = Find_no_this_line(s);
            b.trade_id = res;       
        }

        if(s[0]=='c' && s[1]=='a')
        {
            fin >> s;
            //cout << s << endl;
            res = Find_no_this_line(s);
        }

        if(s[0]=='m' && s[1]=='i')
        {
            fin >> s;
            res = Find_no_this_line(s);
            b.mid = res;
        }

        if(s[0]=='t' && s[1]=='i')
        {
            fin >> s;
            res = Find_no_this_line(s);
            b.time = res;
        }

        if(s[0]=='p' && s[1]=='a')
        {
            fin >> s;
            res = Find_no_this_line(s);
            b.paid_amount = res;
        }

        if(s[0]=='c' && s[1]=='h')
        {
            fin >> s;
            res = Find_no_this_line(s);
            b.change_amount = res;
        }
        
        if(s[0]=='a' && s[1]=='l')
        {
            fin >> s;
            res = Find_no_this_line(s);
            b.alipay = res;
        }

        if(s[4]=='n' && s[5]=='o')
        {
            fin >> s;
            res = Find_no_this_line(s);
            b.VIP_no = res;
        }

        if(s[4]=='p' && s[5]=='o')
        {
            fin >> s;
            res = Find_no_this_line(s);
            b.VIP_points = res;
        }
    }

    cout << "                        Loading..." << endl;
    cout << endl;
    cout << "                        Load complete! For more:";
    sleep(1);
    cout << endl;
    cout << endl;

    char cho;
    cout << "                        [V] View the bill." << endl;
    cout << "                        [L] Load more bill." << endl;
    cout << "                        [B] Back to main page." << endl;
    cout << endl;
    cout << "                        Enter here: ";
    cin >> cho;
    system("clear");
    cout << endl;
    cout << endl;

    cout << "          ***********************************************************";
    cout << endl;

    while(cho!='V' && cho!='L' && cho!='B')
    {
        cout << "                        WRONG INPUT! Enter again: ";
        cin >> cho;
    }

    if(cho=='V')
    {
        cout << "                                     GOODS" << endl;

        for(int i=0; i<count; i++)
        {
            cout << b.goods[i].name << " ";
            cout <<"| ";
        }
        cout << endl;
        cout << endl;

        cout << "              trade no: " << '\t' <<  b.trade_id << endl;
        cout << "              cashier no: " << '\t' << b.cashier_id << endl;
        cout << "              cash machine id: " <<   b.mid << endl;
        cout << "              trade time: " << '\t' <<  "20" << b.time << endl;

        cout << endl;
        if(!b.paid_amount) 
        {
            cout << "              The customer payed with Alipay." << endl;
        }
        else
        {
            cout << "              The customer paid with cash." << endl;
            cout << "              paid amount: " << b.paid_amount;
            cout << endl;
            cout << "              change amount: " << b.change_amount << endl;
        }

        cout << endl;

        if(!b.VIP_no) 
        {
            cout << "              The customer is not VIP.";
        }
        else
        {
            cout << "              The customer is VIP with VIP number ";
            cout << b.VIP_no << "." << endl;
            cout << "              Now owns " << b.VIP_points << " VIP points." << endl;
        }
        cout << endl;
        cout << endl;

        cout<<"          ***********************************************************";
        cout << endl;
        cout << endl;

        char c;
        cout << "              Press [B] to go back to main page." << endl;
        cout << "              Press [L] to load more bill." << endl;
        cout << endl;

        cout << "          ";
        cin >> c;

        while(c!='B' && c!='L') 
        {
            cout << "              WRONG! Enter again: ";
            cin >> c;
        }
        
        if(c=='B') Entrance(su);
        if(c=='L') Read_file_by_word(su, bill[++bill_count]);
    }
    if(cho=='L')
    {
       Read_file_by_word(su, bill[++bill_count]);
    }

    if(cho=='B')
    {
        Entrance(su);
    }

}

void Show_all_items(Supermarket su)
{
    
    system("clear");
    
    char enter;
    
    cout << endl;
    cout << endl;
    cout << endl;
    
    cout << "          ***********************************************************";
    cout << endl;
    cout << "                                所有商品及其销量 ";
    cout << endl;
    cout << "          ***********************************************************";
    cout << endl;
    cout << endl;
    
    for(int i=0; i<20; i++)
    {
        cout << "name: ";
        cout << su.list[i].name;
        cout << "\t";
        
        cout << "good id: ";
        cout << su.list[i].iid;
        cout << "\t";
        
        cout << "total sale amount: ";
        cout << su.list[i].amount;
        cout << "\t";
        
        cout << "good price: ";
        cout << su.list[i].price;
        cout << "\t";
        
        cout << endl;
        
    }
    
    cout << endl;
    cout << "Press [B] to back to main page";
    cout << endl;
    
    cin >> enter;
    
    if(enter=='B')
    {
        Entrance(su);
    }
    
    else
    {
        cout << "Wrong input! Enter again";
        cout << endl;
        
        cin >> enter;
    }
    
}


void Load_goods(Supermarket &S)
{
    
    Init_good(S.list[0], "维达手帕纸十包装", 1, 6);
    Init_good(S.list[1], "莫斯利安甜橙味", 2, 10);
    Init_good(S.list[2], "百岁山矿泉水", 3, 4);
    Init_good(S.list[3], "爱尚大包虾条", 4, 2);
    Init_good(S.list[4], "娃哈哈AD钙奶", 5, 3);
    Init_good(S.list[5], "乐事原味薯片", 6, 4);
    Init_good(S.list[6], "卫龙辣条袋装", 7, 3);
    Init_good(S.list[7], "统一老坛酸菜面", 8, 5);
    Init_good(S.list[8], "娃哈哈八宝粥", 9, 5);
    Init_good(S.list[9], "黑色中性水笔", 10, 2);
    Init_good(S.list[10], "蓝月亮洗衣液", 11, 15);
    Init_good(S.list[11], "洁丽雅毛巾", 12, 8);
    Init_good(S.list[12], "南孚电池一节", 13, 2);
    Init_good(S.list[13], "六神花露水", 14, 10);
    Init_good(S.list[14], "不二家棒棒糖", 15, 2);
    Init_good(S.list[15], "思念灌汤水饺三鲜", 16, 8);
    Init_good(S.list[16], "郫县豆瓣酱", 17, 12);
    Init_good(S.list[17], "奥妙洗衣液", 18, 23);
    Init_good(S.list[18], "天堂晴雨伞", 19, 49);
    Init_good(S.list[19], "东北盘锦大米", 20, 40);
    
}

//void Show_sale_today(){};
void Search_item(){};
void Show_VIP(){};
void Show_today(){};
void Show_best_sale(Supermarket &su)
{
    Bubble_sort(su);

    cout << su.list[0].name << "   " << su.list[0].amount << endl;
    cout << su.list[1].name << "   " << su.list[1].amount << endl;
    cout << su.list[2].name << "   " << su.list[2].amount << endl;
}


void Entrance(Supermarket su)
{
    
    system("clear");
    
    char enter;
    
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "          ***********************************************************";
    cout << endl;
    cout << "                         Supermarket Management System               ";
    cout << endl;
    cout << "          ***********************************************************";
    cout << endl;
    
    cout << "          [a] 读取账单";
    cout << endl;
    
    cout << "          [b] 查看历史畅销商品";
    cout << endl;
    
    cout << "          [c] 查找商品";
    cout << endl;
    
    cout << "          [d] 会员及积分";
    cout << endl;
    
    cout << "          [e] 查看所有商品及其销量";
    cout << endl;
    
    cout << "          [f] 退出系统";
    cout << endl;
    cout << endl;
    
    cout << "          输入相应编号，进行下一步操作: ";
    cin >> enter;
    //cout << "ok";
    
    while(enter!='a'&& enter!='b'&& enter!='c'&& enter!='d'&& enter!='e'&& enter!='f')
    {
        cout << "          请从以上选项中选择" << endl;
        cout << "          输入相应编号，进行下一步操作: ";
        cin >> enter;
        cout << endl;
    }
    
    if(enter=='a')
    {
        Read_file_by_word(su, bill[bill_count]);
    }
    
    if(enter=='b')
    {
        Show_best_sale(su);
        //Show_sale_today();
    }
    
    if(enter=='c')
    {
        Search_item();
    }
    
    if(enter=='d')
    {
        Show_VIP();
    }
    
    if(enter=='e')
    {
        Show_all_items(su);
    }
    
    if(enter=='f')
    {
        exit(0);
    }
    
}


void Welcome(Supermarket su)
{
    
    string name;
    string pwd;
    
    /*
    cout << "enter ur name here: ";
    cin >> name;
    cout << "Hello, " << name << ", welcome :)";
    cout << endl;
    cout << endl;
    
    do{
        cout << "enter password here: ";
        cin >> pwd;
    } while(pwd!="123456");
    cout << endl;
    
    cout << "Correct.";
    cout << endl;
    cout << "Now you can enter management system.";
    cout << endl;
    */
    
    sleep(2);
    
    Entrance(su);
}


int main(void)
{
    Supermarket su1;

    Init(su1);
    Load_goods(su1);

    /*
    Welcome(su1);

    Item test;
    Copy_good(su1.list[0], test);
    cout << "test" << test.name << endl;
    cout << test.amount;
    cout << test.price;
    cout << test.iid;
    */

    for(int i=0; i<20; i++)
    {
        cout << "name: ";
        cout << su1.list[i].name;
        cout << "\t";

        cout << "good id: ";
        cout << su1.list[i].iid;
        cout << "\t";

        cout << "total sale amount: ";
        cout << su1.list[i].amount;
        cout << "\t";
        
        cout << "good price: ";
        cout << su1.list[i].price;
        cout << "\t";
        cout << endl;
    }

        Bubble_sort(su1);

        for(int i=0; i<20; i++)
        {
            cout << "name: ";
            cout << su1.list[i].name;
            cout << "\t";

            cout << "good id: ";
            cout << su1.list[i].iid;
            cout << "\t";

            cout << "total sale amount: ";
            cout << su1.list[i].amount;
            cout << "\t";

            cout << "good price: ";
            cout << su1.list[i].price;
            cout << "\t";

            cout << endl;
        }   

    return 0;
}
//进货、售货、存储管理

