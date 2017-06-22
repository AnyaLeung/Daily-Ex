#include <iostream>

using namespace std;

class Rectangle{
    private:
        char id;
        int length, height;
        char *words;
    public:
        Rectangle(int l=0, int h=0){
            length = l;
            height = h;
            id = '1';
            cout <<"I'm a rec of height " << height << "and length " << length << endl;

        }
        Rectangle(char a){
            id = a;
            cout << "hi, I'm rec  " << id << endl;
        }
        Rectangle(){
            length = 0;
            height = 0;
            id = '\0';
            cout << "constructor failed" << endl;
        }
        ~Rectangle(){
            cout << "destructor Rec " << id << endl;
        }

        void DrawRec(){
            for(int i=0; i<height; i++){
                for(int j=0; j<length; j++){
                    if(i==0||i==height-1) {
                        cout << "*"; 
                    }
                    else{
                        if(j==0||j==length-1){
                            cout << "*";
                        }
                        else{
                            cout << " ";
                        }
                    }
                }
                    cout << endl;
            }
        }

        void Show(){
            cout << "height: " << height << endl;
            cout << "length: " << length << endl;

        }
        Rectangle(Rectangle &p){
            cout << "copy constructor, before call" << endl;
            height = p.height;
            length = p.length;
        }
};

        int main(void){
            int m = 0, n = 0;
            char a;
            cout << "enter length: ";
            cin >> m;
            cout << "enter height: ";
            cin >> n;

            cout << "enter a letter for next rec: ";
            cin >> a;

            Rectangle rec1(m, n);
            Rectangle rec2gle(a);

            rec1.DrawRec();
            Rectangle rec3(rec1);
            cout << "rec3 " ;
            rec3.Show();


    return 0;
}
