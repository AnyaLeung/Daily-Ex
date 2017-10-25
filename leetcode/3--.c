//Given a string, 
//find the length of the longest substring 
//without repeating characters.

bool check(char cr, char* copy) {
    char* p;

    p = (char *)malloc(len * sizeof(char));
    p = copy;

    while(*p!='\0') {
        if(*p==cr) return false;
        else p++;
    }
    return true;
}

int lengthOfLongestSubstring(char* s) {
    char* tmp[2];
    char* p;
    int len = strlen(s);
    int slen[2] = 0;

    tmp[1] = new char[len];
    tmp[2] = new char[len];
    p = new char[len];
    
    p = s;
    while(*p!='\0') {
        if(check(*p, tmp[1])) {
            tmp[1] += *p;
        }
        else {
            tmp[2] += *p;
        }
    }

    return res;
}
