/* 超时 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int a = n;
        for(int i = m; i < n; i++) {
            a = a & i;
        }
        return a;
    }
};

/*
n的二进制位比m二进制最左边的1高时，&的结果必然为0； 
由这个思想启发，二进制最高位相同时，这个1会保存，然后比较右一位，相同也保留... 
所以只需要m n 同时右移到相等时 m n的值就是&后能保留的位数，然后左移回来就是最后的值。
 */

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int num = 0;
        while(n != m) {
            n >>= 1;
            m >>= 1;
            num++;
        }
        return m << num;
    }
};