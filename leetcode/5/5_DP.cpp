class Solution {
public:
    string longestPalindrome(string s) {
        int slen = s.length();
        string res; 
        bool DP[1000][1000] = {false};

        for(int i=slen-1; i>-1; i--){
            for(int j=i; j<n; j++){
                if((j-i<3||DP[i+1][j-1]) && s[i]==s[j]){
                    DP[i][j] = true;
                    if(DP[i][j] && j+1-i>res.length()){
                        res = s.substr(i, j+1-i);
                    }
                }
            }
        }
        return res;
    }
};
