#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fstream>

#define MAXSIZE 20

using namespace std;

typedef struct
{
    string name;
    int iid;
    int amount;
    float price;
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

void Init(Supermarket &S)
{
    S.list = new Item[MAXSIZE];
    S.pre_class_no = 0;
    S.max_class_no = MAXSIZE;
}
//Init manage system

void Init_good(Item g1, string name, int iid, float price)
{
    g1.name = name;
    g1.iid = iid;
    g1.amount = 0;
    g1.price = price;
}

void Read_bill()
{
    char buffer[256];
    fstream outfile;
    outfile.open("bill1.txt", ios::in);


    while(!outfile.eof()) 
    {
        outfile.getline(buffer, 256, '\n');
        //write content of pointer into buffer[256]
          
        char *p = new char[256];
        p = buffer;

        while(*p!='\0')
        {
           if(*p<='A'|| *p>='z') 
           {
               /*
              if(Is_good(*p)) 
              {

              }
              */
              
              if((*p>='0') && (*p<='9'))
              {
                
              }
           }
        }
       
    }
}

void Show_all_items()
{ }; 

void Load_goods(Supermarket S) 
{

    Init_good(S.list[0], "维达手帕纸十包装", 1, 6);
    Init_good(S.list[1], "莫斯利安甜橙味", 2, 10.5);
    Init_good(S.list[2], "百岁山矿泉水", 3, 4);
    Init_good(S.list[3], "爱尚虾条", 4, 1.8);
    Init_good(S.list[4], "娃哈哈AD钙奶", 5, 2.5);
    Init_good(S.list[5], "乐事薯片", 6, 4.5);
    Init_good(S.list[6], "卫龙辣条", 7, 3);
    Init_good(S.list[7], "统一老坛酸菜面", 8, 4.9);
    Init_good(S.list[8], "娃哈哈八宝粥", 9, 5);
    Init_good(S.list[9], "中性笔", 10, 2);
    Init_good(S.list[10], "蓝月亮洗衣液", 11, 15);
    Init_good(S.list[11], "洁丽雅毛巾", 12, 7.5);
    Init_good(S.list[12], "南孚电池", 13, 2.5);
    Init_good(S.list[13], "六神花露水", 14, 9.9);
    Init_good(S.list[14], "不二家棒棒糖", 15, 2);
    Init_good(S.list[15], "思念灌汤水饺三鲜", 16, 8.5);
    Init_good(S.list[16], "郫县豆瓣酱", 17, 11.9);
    Init_good(S.list[17], "奥妙洗衣液", 18, 22.8);
    Init_good(S.list[18], "天堂晴雨伞", 19, 49);
    Init_good(S.list[19], "盘锦大米", 20, 39.9);
        
}

void Show_sale_today(){};
void Search_item(){};
void Show_VIP(){};
void Show_today(){};
void Add_new_bill(){};

/*
void Entrance()
{
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
    
    cout << "          [b] 查看今日特价商品";
    cout << endl;
    
    cout << "          [c] 查找商品";
    cout << endl;
    
    cout << "          [d] 会员及积分";
    cout << endl;
    
    cout << "          [e] 查看今日汇总";
    cout << endl;
    
    cout << "          [f] 查看所有商品及其销量";
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
        Show_all_items();
    }
    
    if(enter=='b')
    {
        Show_sale_today();
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
       Show_today();
   }
    
    if(enter=='f')
    {
        Add_new_bill();
    }
    
}
*/

void Welcome()
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
     
     sleep(2);
     system("clear");

    Entrance();
     */
}



int main(void)
{
    Supermarket su1;
    Init(su1);
    Load_goods(su1);

    Welcome();
    
    
    return 0;
}
//进货、售货、存储管理
