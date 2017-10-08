class Solution {
    public:
        bool check(char cr, string copy) {
            char* p;

            p = new char[copy.size()]
            p = copy;

            while(*p!='\0') {
                if(*p==cr) return false;
                else p++;
            }
            return true;
        }

        int lengthOfLongestSubstring(string s) {
            char* p;
            if(s.size()==1) return 1;
            p = new char[s.size];
            p = s;

            string s1;
            string s2;
            
            while(*p) {
                
            }
            p = s;
            while(p) {
                if(check(*p, ))
            }
        }
};