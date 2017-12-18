int strStr(char* haystack, char* needle) {
    if(*needle=='\0') return 0;

    for(char *hay=haystack; *hay!='\0'; hay++){ 
        //user pointer rather than i=0 to count
        //use !='\0' for end
        char *p = hay, *q = needle;
        //define inside loop, no need to init every time

        while(*q && (*p==*q)){
            p++;
            q++;
        }

        if(*q=='\0') return hay - haystack; //不懂。。？
        if(*p=='\0') return -1; //把这句加到第九行就老慢了。。？
    }
    return -1;

}

