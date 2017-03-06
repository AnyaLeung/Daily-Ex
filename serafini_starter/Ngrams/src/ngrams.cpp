#include "map.h"
#include "random.h"
#include "vector.h"
#include "simpio.h"
#include "console.h"
#include "lexicon.h"
#include <cctype>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void Welcome(void);
void ReadTextFile(ifstream &infile, Vector<string> &words);
void GenerateNgram(Vector<string> &words, Vector<Vector<string>> &keys, Vector<string> &values, Map<Vector<string>,Vector<string>> &map, int N);
void AskUserForInputFile(string prompt, ifstream &infile);
void GenerateRandom(Map<Vector<string>, Vector<string>> &map, Vector<Vector<string>> &keys, Vector<string> &window, Vector<string> &outputwords, int text_no);
void ShowResult(Vector<string> &outputwords);

int main(void) {
    Welcome();

    ifstream infile;
    AskUserForInputFile("Input file name? ", infile);
    Vector<string> words;
    ReadTextFile(infile, words);
    //infile.close();  can't use?

    cout << "Value of N? ";
    int N;
    cin >> N;
    cout << "\n";

    Vector<Vector<string>> keys;
    Vector<string> values;
    Map<Vector<string>,Vector<string>> map;
    Vector<string> window;
    Vector<string> outputwords;

    GenerateNgram(words, keys, values, map, N);

    int text_no = 1;
    cout << "# of random words to generate (0 to quit)? ";
    //int text_no;  nicht exit loop? y canb redefined while nicht init former? canb without init?
    cin >> text_no;

    while(text_no) {

        GenerateRandom(map, keys, window, outputwords, text_no);
        ShowResult(outputwords);

        cout << "\n";
        cout << "# of random words to generate (0 to quit)? ";
        cin >> text_no;
    }

    cout << "Exiting." << endl;

    return 0;
}

void Welcome(void) {
   cout <<  "Welcome to CS 106B Random Writer ('N-Grams')." << endl;
   cout <<  "This program makes random text based on a document." << endl;
   cout <<  "Give me an input file and an 'N' value for groups " << endl;
   cout <<  "of words, and I'll create random text for you." << endl;
   cout << "\n";
}

void ReadTextFile(ifstream &infile, Vector<string> &words) {
    while (true) {
        string line;
        infile >> line; //y getline(infile, line) doesn't work? (split into lines)
        if (infile.fail()) break;
        words.add(line);
    }
} //Reads an entire file into the Vector<string> supplied by the user.

void AskUserForInputFile(string prompt, ifstream &infile) {
    while (true) {
        cout << prompt;
        string filename;
        cin >> filename;
        infile.open(filename.c_str());
        if (!infile.fail()) break;
        cout << "Unable to open " << filename << endl;
        infile.clear();
    }
} // Opens a text file whose name is entered by the user and give alarm while wrong

//used keys only for random, choosing key by index

void GenerateNgram(Vector<string> &words, Vector<Vector<string>> &keys, Vector<string> &values, Map<Vector<string>,Vector<string>> &map, int N) {
    int no_of_words = words.size();
    Vector<string> present_i_vector;

    for(int i=0; i<no_of_words; i++) {
        if(i<no_of_words-N+1){ //no_of_words-N+1 n' N-1+i?
            for(int j=i; j<N-1+i; j++) {
                present_i_vector.add(words[j]); //save present word into present_i_vector
            }
            //cout << " " << endl;

            string end_word = words.get(N-1+i);
            if(map.containsKey(present_i_vector)==0) {
                values.add(end_word); //save value
                keys.add(present_i_vector); //save present_i_vector into keys
                map.put(present_i_vector, values);
            }
            else {
                values = map.get(present_i_vector);
                values.add(end_word); //save value
                map.put(present_i_vector, values);
            }
            //save all into map n clear all vector
        }
        present_i_vector.clear();
        values.clear();
    }
}

void GenerateRandom(Map<Vector<string>, Vector<string>> &map, Vector<Vector<string>> &keys, Vector<string> &window, Vector<string> &outputwords, int text_no) {
    int map_size = map.size();
    int starting_point = randomInteger(0, map_size-1); //y map.size()-1 nicht?
    outputwords = keys[starting_point];//assign staring vector to outputwords
    window = outputwords; //window has n-1 elements

    while(outputwords.size()<text_no) {
        Vector<string> temp_value = map.get(window); //save all values of the index key
        int value_size = temp_value.size();
        int value_random = randomInteger(0, value_size-1);
        outputwords.add(temp_value[value_random]);

        window.remove(0);
        window.add(temp_value[value_random]);

        temp_value.clear();
        value_size = 0;
        value_random = 0;
    }
}

void ShowResult(Vector<string> &outputwords) {
    cout << "... ";
    for(int j=0; j<outputwords.size(); j++) {
        cout << outputwords[j] << " ";
    }
    cout << " ...";
    cout << "\n";
}

