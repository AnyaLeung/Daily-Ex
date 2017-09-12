// Reverse digits of an integer.
// Overflow after reverse

class Solution {
public:
    long reverse(int x) {
        int res = 0;

        while(x!=0) {
            res = res * 10 + x % 10;
            x /= 10;
            if(res<INT_MIN || res>INT_MAX) return 0; 
            //after reversed overflow
        }
         return res;
    }
};
