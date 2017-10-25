class Solution {
    public:
        bool check(char cr, string copy) {
            char *p;

            p = new char[copy.size()]
            p = copy;

            while(*p!='\0') {
                if(*p==cr) return false;
                else p++;
            }
            return true;
        }

        int lengthOfLongestSubstring(string s) {
            char *p;
            int count = 0;

            if(s.size()==1) return 1;

            p = new char[s.size];
            p = s;

            while(*p) {
                if(check(*p, s)) {
                    count ++;
                    p++;
                }
            }

        }
};
