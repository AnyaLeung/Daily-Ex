class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;

        int sum = 0;
        int tmp = x;

        while(x) {
           sum = sum * 10 +  x % 10;
           x /= 10;
        }

        return sum==tmp;
        //if(sum==tmp) return true;
        //return false;
    }
};
