class Solution {
public:
    bool IsPalidrome(string s){
        char* p, *q;
        p = &s[0];
        q = &s[s.size()-1];
        while(p<=q){
            cout << *p << " ";
            cout << *q << " ";

            if(*p==*q){
                p++;
                q--;
            }
            else break;
        }
        return p>=q;
    }

    string longestPalindrome(string s) {
        string lonS = ("");
        for(int i=0; i<s.size(); i++){
            string S;
            S += s[i];
            for(int j=i+1; j<s.size(); j++){
                S += s[j];
                if(IsPalindrome(S)){
                    (S.size()>lonS.size())? lonS = S : lonS = lonS;
                }
            }
        }

        return lonS;
    }
};
