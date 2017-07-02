#include"stdafx.h"

#include<iostream>

using namespace std ; 

class CGraph{

	public : 

		int type ; 

		int color ; // 大于0，小于100

		int linewidth ; 

		void show () {

			cout << endl ; 

			cout << "GraphMsg:  " << endl ; 

			cout << "Type: " << type << " ( 1 : rect , 2 : circle , 3 : CircleRect ) " << endl ; 

			cout << "Color: " << color << endl ; 

			cout << "Linewidth: " << linewidth << endl ; 

		}  

		virtual void show2() = 0 ; 

		CGraph(int t  , int c  , int l ){

			type = t ; 

			color = c ; 

			linewidth = l ;

		} 

		~CGraph() {

			cout << "Calling CGraph!!" << endl ;

		}

} ; 

class CCircle : virtual public CGraph { 

	public : 

		int center[2] ; 

		int radius ; 

		CCircle(int t , int c , int l , int a[2] , int r) : CGraph(t,c,l){ 

			center[0] = a[0] ; 

			center[1] = a[1] ;

			radius = r ; 

		}

		void show2() {

			cout << "CircleMsg: " << endl ;

			cout <<"Center point: ( " << center[0] << " , " << center[1] << " ) " << endl ;

			cout <<"Radius: " << radius << endl ;

		}

		~CCircle() {

			cout << "Calling ~CCircle!" << endl ; 

		}

};

class CRect : virtual public CGraph { 

	public : 

		int start[2] , h , w ; 

		CRect(int t , int c , int l , int a[2] , int m , int n ) :CGraph(t,c,l) { 

			start[0] = a[0] ; 

			start[1] = a[1] ; 

			h = m ; 

			w = n ;

		}

		void show2() {

			cout <<"RectMsg: " << endl ; 

			cout <<"start point: ( " << start[0] <<" , " << start[1] << " ) " << endl ;

			cout <<"High: " << h << endl ; 

			cout <<"Width: " << w << endl ;

		}

		~CRect () {

			cout << "calling ~CRect!" << endl ; 

		}

} ; 

class CCR : public CCircle , public CRect { 

	public : 

		CCR(int t , int c ,int l , int a[2] , int b[2] , int r , int m , int n ) :CCircle(t,c,l,a,r),CRect(t,c,l,b,m,n),CGraph(t,c,l){

			;  

		}

		void show(){

			cout << endl ; 

			cout << "CircleRect: " << endl ; 

			CGraph::show() ;

			cout << "CircleRectMsg: " << endl ; 

			CCircle::show2() ; 

			CRect::show2() ; 

		}

		void show2() {

			;

		}

		~CCR(){

			cout << "Calling ~CCR" << endl ; 

		}

}; 

			void getC(int s , int num , CGraph *g[100] ){

			int i = 0 , m , n , k[2] , j , z  ; 

			for ( i = s ; i < num ; i++ ) {

				cout << "input the Color , Linewidth , center point and radius  " << endl ; 

				cin >> m >> n >> k[0] >> k[1] >> j  ; 

				g[i] = new CCircle(2,m,n,k,j) ;

			} 

		} 

			void getR(int s , int num , CGraph *g[100] ){

			int i = 0 , m , n , k[2] , j , z  ; 

			for ( i = s ; i < num ; i++ ) {

				cout << "input the Color , Linewidth , start point , high and width  " << endl ; 

				cin >> m >> n >> k[0] >> k[1] >> j >> z ; 

				g[i] = new CRect(1,m,n,k,j,z) ;

			} 

		} 

			void getCR(int s , int num , CGraph *g[100]) {

			int i = 0 , m , n , k[2] , j , z , d[2] , o ;

			for ( i = s ; i < num ; i++ ) {

				cout << "input the Color , Linewidth ,center point , start point , radius , high and width  " << endl ; 

				cin >> m >> n >> k[0] >> k[1] >> d[0] >> d[1] >> o >>j >> z ; 

				g[i]  = new CCR(3,m,n,k,d,o,j,z) ;

			}

		}

class Page {

	public : 

		int rnum , cnum , anum  ;

		CGraph *g[100] ; 

		Page(int m = 1 , int n = 1 ,int l = 1 ) {

			rnum = m ; 

			cnum = n ; 

			anum = l ;

		}

		void getinput(){  

			cout <<"input " << cnum << " circles " << endl ;

			getC(0,cnum,g) ;

			cout <<"input " << rnum << " rects " << endl ; 

			getR(cnum,cnum+rnum,g) ; 

			cout <<"input " << anum << " CircleRects " << endl ; 

			getCR(cnum+rnum,cnum+rnum+anum,g); 

		}

		void show ( ) {

			cout << endl ; 

			cout << endl ; 

			cout << "Show : " << endl ;

			for ( int i = 0 ; i < anum + cnum + rnum ; i++ ) {

				g[i]->show() ; 

				if ( g[i]->type != 3) {

					g[i]->show2(); 

				}

			}

		}

		~Page() { 

			cout << "calling ~Page!!" << endl ; 

		}

};	

int main() {

	int a , b , c ; 

	cout << " input the number of rect , circle and CircleRect" << endl ; 

	cin >> a >> b >> c ;  

	Page page(a,b,c) ; 

	page.getinput() ; 

	page.show() ; 

	return 0 ; 

}
