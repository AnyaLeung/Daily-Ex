#include "genlib.h"
#include "simpio.h"
#include "vector.h"
#include <string>
#include <iostream>
#include <fstream>

/*function prototypes*/
void ReadTextFile(ifstream & infile, Vector<string & lines);
void AskUserForInputFile(string prompt, ifstream & infile);
void PrintReversed(Vector<string> & lines);

int main(void){
    ifstream infile;
    AskUserForInputFile("Input file:", infile);
    Vector<string> lines;
    ReadTextFile(infile, lines);
    infile.close();
    PrintReversed(lines);
    
    return 0;
}

void ReadTextFile(ifstream & infile, Vector<string> & lines) {
    while (true){
        string line; 
        getline(infile, line);
        if (infile.fail()) break;
        lines.add(line);
    }
}

void AskUserForInputFile(string prompt, ifstream & infile) {
    while(true){
    cout << prompt;
    stringfilename = GetLine();
    infile.open(filename.c_str());
    if (!infile.fail()) break;
    cout << "Unable to open" <<filename <<endl;
    infile.clear();
    }
}

void PrintReversed(Vector<string> & lines) {
    for(int i=line.size()-1; i>=0; i--){
        cout << lines[i] << endl;
    }
}
