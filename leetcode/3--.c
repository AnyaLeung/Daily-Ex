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
    char* tmp;
    int res = 0;
    int len = strlen(s);
    int slen1 = 0;
    int slen2 = 0;

    tmp = (char *) malloc(len * sizeof(s));
    tmp = s;

    while(*p!='\0') {
        
    }

    return res;
}
