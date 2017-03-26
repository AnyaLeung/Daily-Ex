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
                        string next_word = word;
                        next_word[i] = 'a' + j;
                        if (next_word==end_word) {
                            ladder.push(next_word);
                            return ladder;
                        }
                        if (lexicon.contains(next_word)&& !usedWords.contains(next_word)) {
                            Stack<string> next_wordLadder = ladder;
                            next_wordLadder.push(next_word);
                            queue.enqueue(next_wordLadder);
                            usedWords.add(next_word);
                        }
                    }
                }
            }
        }
        return emptyLadder;
    }*/
