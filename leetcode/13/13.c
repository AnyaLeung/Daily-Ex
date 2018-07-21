enum RomToInt{
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000
};

int romanToInt(char* s) {
    char *p = s;                
    int res = 0;
    
    while(p+1){
        bool sign = 1; //for +
        if(*p<*(p+1)){
            sign = 0;     
        }
        (sign>0)? (res += *p): (res -= *p);
        p++;
    }
    return res;
}
