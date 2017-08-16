// 装水的坑，要面积最大喔
int maxArea(int* height, int heightSize) {
    int *p1 = height, *p2;
    int marea = 0, ht = 0, tmp = 0;
    int i = 0, j = heightSize - 1;

    p2 = p1 + heightSize - 1;
    while(i<j){
        ht = (*p1<*p2)? *p1:*p2;
        tmp = (j - i) * ht;
        marea = (tmp>marea)? tmp:marea;
        if(*p1<*p2) {
            p1++;
            i++;
        }
        else {
            p2--;
            j--;
        }
    }
    return marea;
}

// 因为写了好久所以简单总结一下QWQ
// 
//
// 面积是长和高同时决定的，高是两根里面较短的一根的长度
// 
// 先取第一个和最后一个，此时长是最长的，算面积
// 在下面的过程中，长只能变得更短
// 所以高要越来越高，才可能有更大的面积
// 
// 因而两者中较短的一根，要被下（上 一个替换掉
// 
// 时间复杂度：O(n)
//
// 然后[对于时间复杂度的另一种理解](https://leetcode.com/problems/container-with-most-water/discuss/)
