/ 实验四_余依蕾.cpp : Defines the entry point for the console application.

#include "stdafx.h"

#include<iostream>

using namespace std ;

	class  juzhen { 

	public : 

		int start[2] , end[2] , high , width ; 

		char *word ;

	public : 

		juzhen( int Start[2] , int High = 3 , int Width = 3 ) {

			high = High ; 

			width = Width ; 

			start[0] = Start[0] ; 

			start[1] = Start[1] ; 

			end[0] = start[0] + high ; 

			end[1] = start[1] + width ;  

		}

		juzhen (int start1 = 0 , int start2 = 0 , int end1 = 3 , int end2 = 3 ) {

			high = end1 - start1 ; 

			width = end2 - start2 ;

			start[0] = start1 ; 

			start[1] = start2 ; 

			end[0] = end1 ; 

			end[1] = end2 ; 

		}

		void getword() { 

			int len1 = width - 4 ; 

			word = new char(len1+1) ; 

			cout<<" input " << len1 << " words " << endl ; 

			cin >> word ; 

			cout << word << endl ;

		}

		void draw() { 

			int len2 = high/2 , i , j  ;

			cout << endl ; 

			cout << endl ; 

			for ( i = 0 ; i < start[0] ; i++ ) {

				for ( j = 0 ; j < start[1] ; j++ ) {

					cout << " " ; 

				}

				cout << endl ; 

			}

			for ( i = 0 ; i < start[0] ; i++ ) {

				cout << " " ; 

			}

			for ( i = 0 ; i < width ; i++ ) 

				cout << "*" ; 

			for ( j = 1 ; j < high - 1 ; j++ ) {

				cout << endl ;

				for ( i = 0 ; i < start[0] ; i++) 

					cout << " " ; 

				if ( j != len2 ) { 

					cout << "*" ;

					for ( i = 1 ; i < width-1 ; i++ ) 

						cout <<" " ; 

					cout << "*" ; 

				}

				else {  

					cout <<"* " ; 

					cout << word ; 

					cout << " *" ; 

				}

			}

			cout << endl ;

			for ( i = 0 ; i < start[0] ; i++ ) {

				cout << " " ; 

			}

			for ( i = 0 ; i < width ; i++ ) 

				cout << "*" ; 

			cout << endl ; 

		}

		juzhen (juzhen &p ) { 

			start[0] = p.start[0] ; 

			start[1] = p.start[1] ; 

			high = p.high ; 

			width = p.width ;

			int len  = strlen(p.word) ;

			if ( len != 0 ) {

				word = new char(len+1) ; 

				strcpy(word,p.word) ; 

			}

		}

		~juzhen() {

			cout << endl ; 

			delete word ; 

		}

	} ;  

	class Page { 

		public : 

			int number ; 

			juzhen *ps ; 

			juzhen b ; 

			static int all ; 

			Page(int a = 3  ) {

				number = a ;

				ps = new juzhen[number];

			}

			void getinput() {

				int i ; 

				cout << " input " << number << " juzhen " << endl ; 

				for ( i = 0 ; i < number ; i++ ) {

					int high  , width  ; 

					cout << " input high and width " << endl ; 

					cin >> high >> width ;

					cout << endl ; 

					cout << " input the start point " << endl ; 

					int start[2] ; 

					cin >> start[0] >> start[1] ;

					ps[i] = juzhen(start,high,width) ;

					ps[i].getword() ; 

				}

			}

			void show (  ) {

				int i ; 

				for (  i = 0 ; i < number ; i++ ) {

					cout << endl ; 

					cout << i+1  << " : start point ( "<< ps[i].start[0] << "," << ps[i].start[1] << ") , end point : ( "  << ps[i].end[0]<<"，" << ps[i].end[1] << ")"  ; 

					cout << " word : " << ps[i].word << endl ;

					cout << endl ;

					all++ ; 

				}

				cout << endl ; 

				cout << all << " in sum " << endl ; 

				for (  i = 0 ; i < number ; i++ ) 

					ps[i].draw() ;  

			} 

			void getB( juzhen ) { 

				b.getword() ; 

			}

			~Page() {

				delete ps ; 

			}

		} ;

	int Page::all = 0 ; 

	int main(){ 

			int num ; 

			cout << "input number " << endl ; 

			cin >> num ;

			Page a(num) ;

			juzhen b(1,1,10,10) ; 

			a.getinput() ; 

			a.show() ;

			a.getB(b) ; 

	return 0;

    }

