class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int sz = num.size();
        if(num.at(0) < num.at(sz-1)) {
            return num.at(0);
        }
        int low = 0, high = sz - 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(num[low] == num[mid] && num[high] == num[mid]) {
                //Brute force
                int min = 0x7fffffff;
                for(int i = low; i <= high; i++) {
                    if(num[i] < min) {
                        min = num[i];
                    }
                }
                return min;
            } else if(num[low] <= num[mid]) {
                low = mid + 1;
                if(low < sz && num[mid] > num[low]) {
                    return num[low];
                }
            } else if(num[mid] <= num[high]) {
                high = mid - 1;
                if(high >= 0 && num[high] > num[mid]) {
                    return num[mid];
                }
            }
        }
        return num[low];
    }
};
