nclude "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

fstream output;
fstream input;	


class CGraph
{

	protected:
		int Type;
		int Color;
		int Linewidth;
	public:
		CGraph() { }

		virtual void getInfo() {cout << "GetInfo Function： " <<endl;}

		virtual void show(){cout << "Show Infomation： " <<endl;}

		virtual ~CGraph() {cout << "~CGraph() called" <<endl;}

};

class CRectangle: public CGraph
{

	public:
		float X;
		float Y;
		float Len;
		float Hei;


		CRectangle()
		{ }

		void show()
		{
			
			output << "Rectangle:"<<endl;
			output << "Type:" <<Type << " Color:" << Color << " Linewidth:" <<Linewidth <<endl;
 			output << "X:"<< X << " Y:" << Y << "Length: " << Len << " Height " << Hei<<endl;

		}

		void getInfo(){
			int X,Y,length,height;
			int type,color,linewidth;
			
			input >> X >> Y >> length >> height;

			input >> type >> color >> linewidth;

			this->X = X;
			this->Y = Y;
			this->Len = length;
			this->Hei = height;
			this-> Linewidth = linewidth;
			this-> Type = type;
			this-> Color = color;
		}

		~CRectangle(){cout << "~CRectangle()called"<<endl;}

};

class CCircle: public CGraph
{
	public:
		float X;
	 	float Y;
		float R;
		char *Info;
	
		CCircle()
		{
		}

		void show()
		{
			output << "CCircle:"<<endl;
			output << "X:" <<X << " Y:" <<Y<<" R:"<<R<<endl;
			output << "Type:" <<Type << " Color:" <<Color << " Linewidth:" <<Linewidth << endl;
			output <<endl;
		}

		void getInfo(){
			
			int X,Y,R;
			int type,color,linewidth;

			
			input>> type>>color>>linewidth;

			
			input >> X >> Y >> R;


			this->X = X;
			this->Y = Y;
			this->R = R;
			this->Type = type;
			this->Color = color;
			this->Linewidth = linewidth;

		}
};


class CPPage {
	private:
		int Num;
		CGraph ** graphs;
	public:

		CPPage(int num)
		{
			this->Num=num;
			graphs = new CGraph * [Num];
		}
		void Set()
		{
			for(int i=0;i<Num;i++){
				int type;
				input >> type;

				if(type==1)
					graphs[i] = new CRectangle;
				else if(type==2)
					graphs[i] = new CCircle;

				graphs[i]->getInfo();
			}
		}
		void showMsg()
		{
			for(int i=0;i<this->Num;i++)
			{
				graphs[i]->show();
				output << endl;
			}
		}
};

void Greet()
{

}

int main()
{

	input.open("input.txt");
	if(!input)
	{
		cerr << " INPUT File opne Error" <<endl;
		exit(1);
	}

	output.open("output.txt",ios::out|ios::trunc);
	if(!output)
	{
		cerr<< "OUTPUT File opne Error" <<endl;
		exit(1);
	}



	int num;
	input >> num;

	CPPage page(num);
	page.Set();
	page.showMsg();

	output.close();
	return 0;
}
