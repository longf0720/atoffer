class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        if(0 == n) return 1 % b;
        
        long long product = fastPower(a, b, n/2);
        int res = 0;
        if(n & 0x1) res = (((product * product) % b) * (a % b)) % b;
        else res = (product * product) % b;
        return (int)res;
    }
};
/*
NOTE: 本题说明a，b，n都是32位整型数，所以product * product一定可以用一个64位整型数表示，因此定义为long long类型
0x7fffffff * 0x7fffffff = 4611686014132420609
0x7fffffffffffffff = 9223372036854775807
*/