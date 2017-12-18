class Solution {
public:
    bool stringContainsChar(string s, char ch){
        for(int i=0; i<s.size(); i++){
            if(s[i]==ch) return true;
        }
        return false;
    }
    
    int lengthOfLongestSubstring(string s) {
        int count1 = 0, count2 = 0, j = 0;
        string nor = ("");
        
        for(int i=0; i<s.size(); i++){
            j = i;
            while(!stringContainsChar(nor, s[j]) && j<s.size()){
                count1++;
                nor += s[j];
                j++;
            }
            count2 = (count1>count2)? count1 : count2;
            count1 = 0;
            nor = "";
        }
        
        return count2;
    }
};
