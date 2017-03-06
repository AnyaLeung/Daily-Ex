#include <cmath>
#include <stack>
#include <cctype>
#include <string>
#include <fstream>
#include <iostream>
#include "stack.h"
#include "queue.h"
#include "simpio.h"
#include "lexicon.h"
#include "console.h"

using namespace std;

string filename;
Lexicon lexicon;

void welcome(void) {
    std::cout << "Welcome to CS 106B Word Ladder." << endl;
    std::cout << "Please give me two English words, and I will change the first into the second by changing one letter at a time." << endl;
    std::cout << "\n";
}

void GetFileName(void){
    cout << "Dictionary file name? ";
    cin >> filename;
}

Stack<string> wordladder(string start_word, string end_word) {
    Lexicon lexicon(filename.c_str());
    Queue< Stack<string> > myQ;
    Lexicon usedWords;
    Stack<string> empty;
    Stack<string> mys;

    mys.push(start_word);
    myQ.enqueue(mys);

    while(!myQ.isEmpty()) {
        Stack<string> ladder = myQ.dequeue();
        string topword = ladder.peek();

        if (topword==end_word) {
            return ladder;
        }
        else {
            for (int i=0; i<topword.length(); i++) {
                for (int j=97; j<123; j++) {
                    string next_word = topword;
                    next_word[i] = char(j);
                    if (lexicon.contains(next_word)) {
                        if (!usedWords.contains(next_word)) {
                            Stack<string> copyLadder = ladder;
                            copyLadder.push(next_word);
                            myQ.enqueue(copyLadder);
                            usedWords.add(next_word);
                        }
                        if (next_word==end_word) {
                        ladder.push(next_word);
                        return ladder;
                        }
                    }
                }
            }
        }
    }
    return empty;
}


int main(void) {
    welcome();
    GetFileName();

    cout << "Word #1 (or Enter to quit:)";
    string start_word;
    cin >> start_word;
    cout << "Word #2 (or Enter to quit:)";
    string end_word;
    cin >> end_word;

    Stack<string> ultistack = wordladder(start_word, end_word);

    if(!ultistack.isEmpty()){
           cout << "Ladder from " << end_word << " back to " << start_word << ":"<< endl;
           while (ultistack.size()) {
               cout << ultistack.pop() << " ";
           }
           cout << endl;
       }

        cout << "Have a nice day." << endl;
        return 0;
}

