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

    tmp = (char *) malloc(len * sizeof(s));
    tmp = s;

    while(*p!='\0') {
        if()
        if(check(p[i], res)) {
            res[j++] = p[i];
        }
        p++;
    }
    return res;
}
