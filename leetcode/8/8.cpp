class Solution {
public:
    bool IsNeg(string str){
        return str[0] == '-';
    } // positive return 1
    
    int myAtoi(string str) {
        char* str1;
        int len = str.size();
        str1 = new char[len];
        int res = 0;
        int pos = IsNeg(str);
        
        for(int i=0; i<len; i++){
            str1[i] = str[i];
        }
        //assign string str to char[]
        
        for(int i=0; i<len; i++){
            res *= 10;
            int tmp = 0;
            if(str1[i]>'9' || str1[i]<'0') continue;
            tmp = str1[i] - '0';
            res += tmp;
        }
        
        if(pos) return -res;
        return res;
    }
};
