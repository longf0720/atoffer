ass Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairsI(int n) {
        // write your code here
        int a = 1, b = 1, c = 0;
        if (0 == n) return a;
        else if (1 == n) return b;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
    
    //dp
    //兑零钱模型
    int climbStairs(int n) {
        if(0 == n) return 1;
        int dp[n+1];
        for(int i = 0; i < n +1; i++) {
            dp[i] = 0;
        }
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <=2; j++) {
                if(i >= j) {
                    dp[i] += dp[i-j];
                }
            }
        }
        return dp[n];
    }
};

