#include <cctype>
#include <cmath>
#include "simpio.h"
#include <string>
#include <stack>
#include "stack.h"
#include "queue.h"
#include "lexicon.h"
#include <fstream>
#include <iostream>
#include "console.h"

using namespace std;

string filename;
Lexicon lexicon;

/*
Lexicon loadinto(string filename){
    string line;
    fstream input;
    Lexicon lexicon;
    input.open(filename.c_str());
    while(getline(input,line)){
     lexicon.add(line);
    }
    input.close();
    return lexicon;
}*/

void welcome(void){
    std::cout << "Welcome to CS 106B Word Ladder." << endl;
    std::cout << "Please give me two English words, and I will change the first into the second by changing one letter at a time." << endl;
    std::cout << "\n";
}

void SaveWordsIntoLexicon(void){
    cout << "Dictionary file name? ";
    cin >> filename;

   // loadinto(filename);
} //open file and save words into lexicon

/*Stack<string> wordladder(string start_word, string end_word) {
    Queue<Stack<string>> queue;
    string neighbor;
    Lexicon used;
    Stack<string> stack;
    //declarations

    stack.push(start_word);
    queue.enqueue(stack);

    while (!queue.isEmpty()) { //aint empty
        Stack<string> ladder = queue.dequeue(); //dequeue and give top stack to the stack
        string word = ladder.peek();
        char result_char[100];
        char temp;

        strcpy(result_char, word.c_str());
            int word_length = input_word.length();

            for (int i=0; i<word_length; i++) {
                for(int j=97; j<123; j++) { //用a-z去替换当前字母{
                    temp = result_char[i];
                    result_char[i] = char(j);
                    result_word.assign(result_char);
                    result_char[i] = temp;

                    if(lexicon.contains(result_word)) goto end;
                }
            }
        end:
             neighbor = result_word;

            if (neighbor==end_word) {
                stack.push(neighbor);
                return stack;
            }
            if(lexicon.contains(neighbor)&& !used.contains(neighbor)) {
                    Stack<string> copystack = stack;
                    copystack.push(neighbor);
                    used.add(neighbor);
                    queue.enqueue(copystack);
                }
            }
        return stack;
        }
*/

    /*Stack<string> wordladder(string start_word, string end_word) {
        Queue< Stack<string> > queue;
        Lexicon usedWords;
        Stack<string> emptyLadder;

        Stack<string> stack;

        stack.push(start_word);
        queue.enqueue(stack);

        while(!queue.isEmpty()) {
            Stack<string> ladder = queue.dequeue();
            string word = ladder.peek();

            if (word==end_word) return ladder;
            else {
                for (int i=0; i<word.length(); i++) {
                    for (int j=0; j<26; j++) {
                        string next = word;
                        next[i] = 'a' + j;
                        if (next==end_word) {
                            ladder.push(next);
                            return ladder;
                        }
                        if (lexicon.contains(next)&& !usedWords.contains(next)) {
                            Stack<string> nextLadder = ladder;
                            nextLadder.push(next);
                            queue.enqueue(nextLadder);
                            usedWords.add(next);
                        }
                    }
                }
            }
        }
        return emptyLadder;
    }*/


Stack<string> wordladder(string start_word, string end_word) {

    Lexicon lexicon(filename.c_str());
    Queue< Stack<string> > pQueue;
    Lexicon usedWords;
    Stack<string> emptyLadder;

    Stack<string> s;

    s.push(start_word);
    pQueue.enqueue(s);

    while(!pQueue.isEmpty()) {

        Stack<string> ladder = pQueue.dequeue();
        string word = ladder.peek();

        if (word == end_word) {
            return ladder;
        } else {
            for (int i = 0; i < word.length(); i++) {
                for (int j = 0; j < 26; j++) {
                    string next = word;
                    next[i] = 'a' + j;
                    if (next == end_word) {
                        ladder.push(next);
                        return ladder;
                    }
                    if (lexicon.contains(next) &&
                            !usedWords.contains(next)) {
                        Stack<string> nextLadder = ladder;
                        nextLadder.push(next);
                        pQueue.enqueue(nextLadder);
                        usedWords.add(next);
                    }
                }
            }
        }
    }
    return emptyLadder;
}


int main() {
    welcome();
    SaveWordsIntoLexicon();

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

