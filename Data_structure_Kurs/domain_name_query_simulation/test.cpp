class treeNode{
    public:
        treeNode():data(NULL),left(NULL),right(NULL)
    {
    }
        treeNode(char* dat):data(dat),left(NULL),right(NULL)
    {

    }
        char* data;//数据格式 www或.taobao   或者  0.0.0.0
        treeNode* left;
        treeNode* right;
};

class binTree//IP二叉树，孩子兄弟表示法，函数bool返回时TRUE凡是成功，否则失
{
    public://外部函数接口
        binTree():initalFlag(false)
    {
    }
        bool Initialize();//从IP数据库读取数据，并形成IP二叉树，IP数据在倒数第二结点的左孩子里面
        char* searchIP(string website);//查找IP，参数为网站名称，例如：www.taobao.com
        void edit(string IP,string websiteWithoutIP);//查找是否存在该网站，否则不进行编辑
        bool addNew(string input);//先验证输入是否正确，然后添加新网站和其IP到二叉树和数据库
        void destory()
        {
            destoryNodes(root);
        }
        ~binTree()
        {
        }
        bool initalFlag;
private://内部封装函数和成员
  void addNewWebsite(string website);//添加新数据到二叉树，参数为带IP的网址名称，例如：www.cau.edu.cn/0.0.0.0
  bool writeToFile(string websiteWithIP);//将带IP地址的网址名称写入文件尾部
  bool editIP(string IP,char*& dataPointer,string websiteWithoutIP);//编辑存在网站的IP数据，参数分别是IP,指向IP的指针，和该网站的名称
  treeNode* insertNode(treeNode*& head,const char* data);//向HEAD所指向指针的孩子区添加内容为data的结点，如果存在则不添加
  void spiltWebsite(string& website,string* IPaddress,string* domain);//将带有IP网站数据分成IP数据，和各个小结点例如：www.taobao.com/0.0.0.0分成0.0.0.0到IPADDRESS和www，.taobao，.com到domain string 数组
  treeNode* searchParts(const char* part,treeNode* level,char*& lastPointer);//查找PART所指向的数据，（.com），level为该数据所在的层级，lastpointer当涉及孩子结点的ip数据时，才赋值，一般为null
  bool checkStringFormat(string toBeChecked,bool whetherHasIP,bool IPpart);//检查string数据是否符合IP格式或网站名称或带IP的网站名称
  void destoryNodes(treeNode*& current);//删除二叉树所有结点以及数据
  treeNode* root;//根结点，不附加内容。左结点指向IP二叉树
};


bool binTree::Initialize()
{
  root=new treeNode;
  root->data=new char[11];
  strcpy(root->data,"SystemHead");
  fstream manipulate;
  string website;
  char buffer[100];
  manipulate.open("IPDB.txt",ios::in);
  if (manipulate.is_open())
  {
    while (!manipulate.eof())
    {
      manipulate.getline(buffer,100,'\n');
      website=buffer;
      addNewWebsite(website);
    
    manipulate.close();
    initalFlag=true;
    return true;
  }
  else
  {
    cout<<"Fail to load data to read."<<endl;
    manipulate.close();
    initalFlag=false;
    return false;
  }
}

bool binTree::addNew(string input)
{
  if (checkStringFormat(input,true,NULL))
  {
	  addNewWebsite(input);
	  return writeToFile(input);
  }
  else
  {
    cout<<"Fail to add"<<input<<endl;
    return false;
  }
}

bool binTree::writeToFile(string websiteWithIP)
{
  fstream writeFile("IPDB.txt",ios::out|ios::app);
  if (writeFile.is_open())
  {
    const char* toBeSaved=websiteWithIP.c_str();
    writeFile.write(toBeSaved,strlen(toBeSaved)*sizeof(char));
    writeFile<<endl;
    writeFile.close();
    return true;
  }
  else
  {
    writeFile.close();
    cout<<"Can't open the file to write."<<endl;
    return false;
  }
}

char* Tree::searchIP(string website
  string domain[4];
  const char* parts[4];
  spiltWebsite(website,NULL,domain);
  for (int i=0;i<4;++i)
  {
    parts[i]=domain[i].c_str();
  }
  int count=strlen(parts[3])?4:3;
  bool flag;
  char* lastPointer="null";
  treeNode* temp=root;
  while (count--)
  {
    temp=searchParts(parts[count],temp,lastPointer);
    if (temp==NULL)
    {
      return NULL;
    }
  } 
  return lastPointer;
}

void binTree::edit(string IP,string websiteWithoutIP)
{
  char * data=NULL;
  data=searchIP(websiteWithoutIP);
  if (data!=NULL && editIP(IP,data,websiteWithoutIP))
  {
      return;
  }
  cout<<"无该网站，无法编辑或者格式错误"<<endl;
}

void binTree::addNewWebsite(string website)
{
    string IPaddress;
    string domain[4];
    spiltWebsite(website,&IPaddress,domain);
    int count=domain[3].length()?4:3;//条件运算符
    treeNode* current=root;
    for (int i=count-1;i>=0;--i)
    {
        const char* temp=domain[i].c_str();
        current=insertNode(current,temp);
    }
    char* content=new char[IPaddress.length()+1];


    for (int i=0;i<=IPaddress.length();++i)
    {
        content[i]=IPaddress[i];
    }
    current->left=new treeNode(content);
}

treeNode* binTree::insertNode(treeNode*& head,const char* data)
{
    treeNode* child=head;
    if (child->left!=NULL)//左孩子为空表示head下面没有数据
    {
        child=child->left;//如果存在，则查找head的所有孩子
        if (!strcmp(child->data,data))//比较字符串数据，匹配成功返回0,所以!0=1
        {
            return child;
        }
        while (child->right!=NULL && strcmp(child->right->data,data))//不匹配继续查找
        {
            child=child->right;
        }
    if (child->right == NULL)//查找失败，则新建
    {
      child->right=new treeNode;
      child->right->data=new char[strlen(data)+1];
      strcpy(child->right->data,data);
      return child->right;      
    }
    else
    {
      return child->right;
    }
  }
  else
  {
    child->left=new treeNode;
    child->left->data=new char[strlen(data)+1];
    strcpy(child->left->data,data);
    return child->left;
  }
}

void binTree::spiltWebsite(string& website,string* IPaddress,string* domain)
{
  int position=website.find_first_of('/');
string i
  if (position!=-1)//防止多余的空格导致错误
  {
    ip=website.substr(position+1,website.length()-position);//IP地址
    website.erase(position,ip.length()+1);//删除IP地址部分
    if (IPaddress!=NULL)
    {
    	//IP地址
      *IPaddress=ip;
    }
  }
    //下面还是分组website
    int count=0;
    int j=0;//i means begin and j means the end
    unsigned int i=j;
    while (1)
    {
      for (;i<website.length() && website[i]!='.';++i);
      domain[count]=website.substr(j,i-j);
      if (i==website.length())//最后一次赋值完后，return
      {
        return;
      }
      j=i;
      ++i;//进入下一次循环准备
      ++count;
    }
}

treeNode* binTree::searchParts(const char* part,treeNode* level,char*& lastPointer)
{
  treeNode* current=level->left;
  if (current==NULL)
  {
    return NULL; 
  }
  while (strcmp(current->data,part) && current->right!=NULL )
  {
    current=current->right;
  }
  if (!strcmp(current->data,part))
  {
    if (lastPointer!=NULL)
    {
      for (int i=0;i<strlen(current->data);++i)
      {
        if (current->data[i]=='.')
        {
          return current;
        }
      }
      lastPointer=current->left->data;
    }
    return current;
  }
  return NULL;
}

bool binTree::checkStringFormat(string toBeChecked,bool whetherHasIP,bool IPpart)
{
  if (!whetherHasIP)
  {
    if (toBeChecked[0]=='.'||toBeChecked[toBeChecked.length()-1]=='.')
    {
      return false;
    }
    for (int i=1;i<toBeChecked.length()-1;++i)
    {
      bool flag=isalpha(toBeChecked[i])&&!IPpart;
      if (isdigit(toBeChecked[i])||flag)
      {
        continue;
      }
      else if(toBeChecked[i]=='.')
      {
        if (toBeChecked[i-1]=='.'||toBeChecked[i+1]=='.')
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    return true;
  } 
  else
  {
    int interval=toBeChecked.find_first_of('/');
    if (interval!=-1)
    {
	    int length2=toBeChecked.length()-interval;
	    return checkStringFormat(toBeChecked.substr(0,interval),false,false)&&
	      checkStringFormat(toBeChecked.substr(interval+1,length2),false,true);
    }
    return false;
  }
}

void binTree::destoryNodes(treeNode*& current)
{
  if (current->left!=NULL)
  {
    destoryNodes(current->left);
  }
  if (current->right!=NULL)
  {
    destoryNodes(current->right);
  }
  if (current->data!=NULL)
  {
    delete[] current->data;
  }
  delete current;
}

bool binTree::editIP(string IP,char*& dataPointer,string websiteWithoutIP)
{
  if (checkStringFormat(IP,false,true))
  {
    delete[] dataPointer;//delete at first and then new a exact size of space
    dataPointer=new char[IP.length()+1];
    strcpy(dataPointer,IP.c_str());
    string fullWebsite=websiteWithoutIP+'/'+IP;
    writeToFile(fullWebsite);
    return true;
  }
  else
  {
    return false;
  }
}

/*
#include <fstream>
#include <iostream>
#include <string>
clude "binTree.h"
using namespace std;
*/
 int main()
{
  binTree domainTree;
  const char str[]="1.IP二叉树初始化 2.查找IP  3.添加新数据 4.编辑IP  5.销毁二叉树 6.退出程序 ";
  string websiteWithoutIP,websiteWithIP,newIP;
  char whetherDestory;
  bool result;
  char* output;
  while (true)
  {
    cout<<str<<endl;
    char option;
    cin>>option;
	  switch (option)
	  {
	  case '1':
	    if (!domainTree.initalFlag)
	    {
	    	result=domainTree.Initialize();
        if (result==false)
        {
          cout<<"there is a failure"<<endl;
        }
	    }
      else
      {
        cout<<"wrong command"<<endl;
      }
	  	break;
	  case '2':
      if (domainTree.initalFlag)
      {
	      cout<<"please input a domain,for instance: www.taobao.com"<<endl;
		    cin>>websiteWithoutIP;
		    output=domainTree.searchIP(websiteWithoutIP);
        if (output!=NULL)
        {
          cout<<output<<endl;
        } 
        else
        {
          cout<<"there is a failure"<<endl;
      
      }
      else
      {
        cout<<"wrong command"<<endl;
      }
	    break;
	  case '3':
      if (domainTree.initalFlag)
      {
	      cout<<"please input a domain with an ip,for instance: www.taobao.com/0.0.0.0"<<endl;
		    cin>>websiteWithIP;
		    result=domainTree.addNew(websiteWithIP);
        if (result==false)
        {
          cout<<"there is a failure"<<endl;
        }
      }
      else
      {
        cout<<"wrong command"<<endl;
      }
	    break;
	  case '4':
      if (domainTree.initalFlag)
      {
	      cout<<"please input an IP,for instance: 0.0.0.0"<<endl;
		    cin>>newIP;
	      cout<<"please input a domain,for instance: www.taobao.com"<<endl;
	      cin>>websiteWithoutIP;
		    domainTree.edit(newIP,websiteWithoutIP);
      }
      else
      {
        cout<<"wrong command"<<endl;
      }
	    break;
	  case '5':
      if (domainTree.initalFlag)
      {
	      cout<<"are you sure to destory the domain tree? Y or N"<<endl;
	      cin>>whetherDestory;
	      if (whetherDestory=='Y'||whetherDestory=='y')
	      {
	        domainTree.destory();
          domainTree.initalFlag=false;
	     
     
      else
      {
        cout<<"wrong command"<<endl;
      }
	    break;
	  case '6':
      if (domainTree.initalFlag)
      {
      	domainTree.destory();
      }
	    return 0;
      break;
    default:
      cout<<"wrong command"<<endl;
	  }

class treeNode//结点类
{
public:
  treeNode():data(NULL),left(NULL),right(NULL)
  {
  }
  treeNode(char* dat):data(dat),left(NULL),right(NULL)
  {

  }
  char* data;//数据格式 www或.taobao   或者  0.0.0.0
  treeNode* left;
  treeNode* right;
};

class binTree//IP二叉树，孩子兄弟表示法，函数bool返回时TRUE凡是成功，否则失败
{
public://外部函数接口
  binTree():initalFlag(false)
  {
  }
  bool Initialize();//从IP数据库读取数据，并形成IP二叉树，IP数据在倒数第二结点的左孩子里面
  char* searchIP(string website);//查找IP，参数为网站名称，例如：www.taobao.com
  void edit(string IP,string websiteWithoutIP);//查找是否存在该网站，否则不进行编辑
  bool addNew(string input);//先验证输入是否正确，然后添加新网站和其IP到二叉树和数据库
  void destory()
  {
    destoryNodes(root);
  }
  ~binTree()
  {
  }
  bool initalFlag;
private://内部封装函数和成员
  void addNewWebsite(string website);//添加新数据到二叉树，参数为带IP的网址名称，例如：www.cau.edu.cn/0.0.0.0
  bool writeToFile(string websiteWithIP);//将带IP地址的网址名称写入文件尾部
  bool editIP(string IP,char*& dataPointer,string websiteWithoutIP);//编辑存在网站的IP数据，参数分别是IP,指向IP的指针，和该网站的名称
  treeNode* insertNode(treeNode*& head,const char* data);//向HEAD所指向指针的孩子区添加内容为data的结点，如果存在则不添加
  void spiltWebsite(string& website,string* IPaddress,string* domain);//将带有IP网站数据分成IP数据，和各个小结点例如：www.taobao.com/0.0.0.0分成0.0.0.0到IPADDRESS和www，.taobao，.com到domain string 数组
  treeNode* searchParts(const char* part,treeNode* level,char*& lastPointer);//查找PART所指向的数据，（.com），level为该数据所在的层级，lastpointer当涉及孩子结点的ip数据时，才赋值，一般为null
  bool checkStringFormat(string toBeChecked,bool whetherHasIP,bool IPpart);//检查string数据是否符合IP格式或网站名称或带IP的网站名称
  void destoryNodes(treeNode*& current);//删除二叉树所有结点以及数据
  treeNode* root;//根结点，不附加内容。左结点指向IP二叉树
};

bool binTree::Initialize()
{
  root=new treeNode;
  root->data=new char[11];
  strcpy(root->data,"SystemHead");
  fstream manipulate;
  string website;
  char buffer[100];
  manipulate.open("IPDB.txt",ios::in);
  if (manipulate.is_open())
  {
    while (!manipulate.eof())
    {
      manipulate.getline(buffer,100,'\n');
      website=buffer;
      addNewWebsite(website);
   
    manipulate.close();
    initalFlag=true;
    return true;
  }
  else
  {
    cout<<"Fail to load data to read."<<endl;
    manipulate.close();
    initalFlag=false;
    return false;
  }
}


bool binTree::addNew(string input)
{
  if (checkStringFormat(input,true,NULL))
  {
	  addNewWebsite(input);
	  return writeToFile(input);
  }
  else
  {
    cout<<"Fail to add"<<input<<endl;
    return false;
  }
}
bool binTree::writeToFile(string websiteWithIP)
{
  fstream writeFile("IPDB.txt",ios::out|ios::app);
  if (writeFile.is_open())
  {
    const char* toBeSaved=websiteWithIP.c_str();
    writeFile.write(toBeSaved,strlen(toBeSaved)*sizeof(char));
    writeFile<<endl;//不要忘记”\n” 
    writeFile.close();
    return true;
  }
  else
  {
    writeFile.close();
    cout<<"Can't open the file to write."<<endl;
    return false;
  }
}
char* binTree::searchIP(string website)
{
  string domain[4];
  const char* parts[4];
  spiltWebsite(website,NULL,domain);
  for (int i=0;i<4;++i)
  {
    parts[i]=domain[i].c_str();
  }
  int count=strlen(parts[3])?4:3;
  bool flag;
  char* lastPointer="null";
  treeNode* temp=root;
  while (count--)
  {
    temp=searchParts(parts[count],temp,lastPointer);
    if (temp==NULL)
    {
      return NULL;
    }
  } 
  return lastPointer;
}
void binTree::edit(string IP,string websiteWithoutIP)
{
  char * data=NULL;
  data=searchIP(websiteWithoutIP);
  if (data!=NULL && editIP(IP,data,websiteWithoutIP))
  {
    return;
  }
  cout<<"无该网站，无法编辑或者格式错误"<<endl;
}
void binTree::addNewWebsite(string website)
{
  string IPaddress;
  string domain[4];
  spiltWebsite(website,&IPaddress,domain);
  int count=domain[3].length()?4:3;//条件运算符
  treeNode* current=root;
  for (int i=count-1;i>=0;--i)
  {
    const char* temp=domain[i].c_str();
    current=insertNode(current,temp);
  }
  char* con tent=new char[IPaddress.length()+1];
  for (  i=0;i<=IPaddress.length();++i)
  {
    content[i]=IPaddress[i];
  }
  current->left=new treeNode(content);
}
treeNode* binTree::insertNode(treeNode*& head,const char* data)
{
  treeNode* child=head;
  if (child->left!=NULL)//左孩子为空表示head下面没有数据
  {
    child=child->left;//如果存在，则查找head的所有孩子
    if (!strcmp(child->data,data))//比较字符串数据，匹配成功返回0,所以!0=1
    {
      return child;
    }
    while (child->right!=NULL && strcmp(child->right->data,data))//不匹配继续查找
    {
      child=child->right;
    }
    if (child->right == NULL)//查找失败，则新建
    {
      child->right=new treeNode;
      child->right->data=new char[strlen(data)+1];
      strcpy(child->right->data,data);
      return child->right;      
    }
    else
    {
      return child->right;
    }
  }
  else
  {
    child->left=new treeNode;
    child->left->data=new char[strlen(data)+1];
    strcpy(child->left->data,data);
    return child->left;
  }
}

void binTree::spiltWebsite(string& website,string* IPaddress,string* domain)
{
  int position=website.find_first_of('/');
  string ip;
  if (position!=-1)//防止多余的空格导致错误
 
    ip=website.substr(position+1,website.length()-position);//IPADDRESS
    website.erase(position,ip.length()+1);//删除IP地址部分
    if (IPaddress!=NULL)
    {
    	//IP地址
      *IPaddress=ip;
    }
  }
    //下面还是分组website
    int count=0;
    int j=0;//i means begin and j means the end
    unsigned int i=j;
    while (1)
    {
      for (;i<website.length() && website[i]!='.';++i);
      domain[count]=website.substr(j,i-j);
      if (i==website.length())//最后一次赋值完后，return
      {
        return;
      }
      j=i;
      ++i;//进入下一次循环准备
      ++count;
    }
  
}

treeNode* binTree::searchParts(const char* part,treeNode* level,char*& lastPointer)
{
  treeNode* current=level->left;
  if (current==NULL)
  {
    return NULL; 
  }
  while (strcmp(current->data,part) && current->right!=NULL )
  {
    current=current->right;
  }
  if (!strcmp(current->data,part))
  {
    if (lastPointer!=NULL)
    {
      for (int i=0;i<strlen(current->data);++i)
      {
        if (current->data[i]=='.')
        {
          return current;
        }
      }
      lastPointer=current->left->data;
    }
    return current;
  }
  return NULL;
}
bool binTree::checkStringFormat(string toBeChecked,bool whetherHasIP,bool IPpart)
{
  if (!whetherHasIP)
  {
    if (toBeChecked[0]=='.'||toBeChecked[toBeChecked.length()-1]=='.')
    {
      return false;
    }
    for (int i=1;i<toBeChecked.length()-1;++i)
    {
      bool flag=isalpha(toBeChecked[i])&&!IPpart;
      if (isdigit(toBeChecked[i])||flag)
      {
        continue;
      }
      else if(toBeChecked[i]=='.')
      {
        if (toBeChecked[i-1]=='.'||toBeChecked[i+1]=='.')
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    return true;
  } 
  else
  {
    int interval=toBeChecked.find_first_of('/');
    if (interval!=-1)
    {
	    int length2=toBeChecked.length()-interval;
	    return checkStringFormat(toBeChecked.substr(0,interval),false,false)&&
	    checkStringFormat(toBeChecked.substr(interval+1,length2),false,true);
   }
    return false;
  }
}
void binTree::destoryNodes(treeNode*& current)
{
  if (current->left!=NULL)
  {
    destoryNodes(current->left);
  }
  if (current->right!=NULL)
  {
    destoryNodes(current->right);
  }
  if (current->data!=NULL)
  {
    delete[] current->data;
  }
  delete current;
}


bool binTree::editIP(string IP,char*& dataPointer,string websiteWithoutIP)
{
  if (checkStringFormat(IP,false,true))
  {
    delete[] dataPointer;//编辑就是先把原来的先删除了再创建新的
    dataPointer=new char[IP.length()+1];
    strcpy(dataPointer,IP.c_str());
    string fullWebsite=websiteWithoutIP+'/'+IP;
    writeToFile(fullWebsite);
    return true;
  }
  else
  {
    return false;
  }
}
2)	Main.cpp
#include <fstream>
#include <iostream>
#include <string>
#include "binTree.h"
using namespace std;

 int main()
{
  binTree domainTree;
  const char str[]="1.IP二叉树初始化 2.查找IP  3.添加新数据 4.编辑IP  5.销毁二叉树 6.退出程序 ";
  string websiteWithoutIP,websiteWithIP,newIP;
  char whetherDestory;
  bool result;
  char* output;
  while (true)
  {
    cout<<str<<endl;
    char option;
    cin>>option;
	  switch (option)
	  {
	  case '1':
	    if (!domainTree.initalFlag)
	    {
	    	result=domainTree.Initialize();
        if (result==false)
        {
          cout<<"there is a failure"<<endl;
        }
	    }
      else
      {
        cout<<"wrong command"<<endl;
      }
	  	break;
	  case '2':
      if (domainTree.initalFlag)
      {
	      cout<<"please input a domain,for instance: www.taobao.com"<<endl;
		    cin>>websiteWithoutIP;
		    output=domainTree.searchIP(websiteWithoutIP);
        if (output!=NULL)
        {
          cout<<output<<endl;
        } 
        else
        {
          cout<<"there is a failure"<<endl;
        }
      }
      else
      {
        cout<<"wrong command"<<endl;
      }
	    break;
	  case '3':
      if (domainTree.initalFlag)
      {
	      cout<<"please input a domain with an ip,for instance: www.taobao.com/0.0.0.0"<<endl;
		    cin>>websiteWithIP;
		    result=domainTree.addNew(websiteWithIP);
        if (result==false)
        {
          cout<<"there is a failure"<<endl;
        }
      }
      else
      {
        cout<<"wrong command"<<endl;
      }
	    break;
	  case '4':
      if (domainTree.initalFlag)
      {
	      cout<<"please input an IP,for instance: 0.0.0.0"<<endl;
		    cin>>newIP;
	      cout<<"please input a domain,for instance: www.taobao.com"<<endl;
	      cin>>websiteWithoutIP;
		    domainTree.edit(newIP,websiteWithoutIP);
      }
      else
      {
        cout<<"wrong command"<<endl;
      }
	    break;
	  case '5':
      if (domainTree.initalFlag)
      {
	      cout<<"are you sure to destory the domain tree? Y or N"<<endl;
	      cin>>whetherDestory;
	      if (whetherDestory=='Y'||whetherDestory=='y')
	      {
	        domainTree.destory();
          domainTree.initalFlag=false;
	      }
      }
      else
    {
        cout<<"wrong command"<<endl;
      }
	    break;
	  case '6':
      if (domainTree.initalFlag)
      {
      	domainTree.destory();
      }
	    return 0;
      break;
    default:
      cout<<"wrong command"<<endl;
	  }
  }
｝
3)	IPDB.TXT 数据文件示例
www.taobao.com/121.0.23.86
www.cau.edu.cn/219.232.107.9
www.baidu.com/121.14.88.76
www.google.com/66.249.89.104
www.yahoo.com.cn/202.165.102.205
www.bb.com/10.2.26.27
www.163.com/12.23.15.48
www.ali213.net/2.2.2.2

