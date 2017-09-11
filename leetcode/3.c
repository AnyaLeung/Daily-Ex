bool check(char cr, char* copy) {
    char* p = copy;
    int len = strlen(copy);

    p = (char *)malloc(len * sizeof(char));
    while(*p!='\0') {
        if()
    }
}

int lengthOfLongestSubstring(char* s) {
    char* res;
    char *p;
    int i = 0, j = 0;
    p = s;
    int len = strlen(s);

    res = (char *) malloc(len * sizeof(char));
    while(*p!='\0') {
        if(check(p[i], res)) {
            res[j++] = p[i];
        }
        p++;
    }
    return res;
}

