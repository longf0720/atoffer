class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int counter = 0;
        while (num) {
            num = num&(num-1);
            counter++;
        }
        return counter;
    }
};

// http://www.cnblogs.com/longf0720/p/6545887.html
