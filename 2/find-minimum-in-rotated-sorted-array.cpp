class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // binary search
        int len = nums.size();
        if (nums.at(len - 1) > nums.at(0)) {
            return nums.at(0);
        }
        // cout<<"len="<<len<<endl;
        int low = 0, high = len - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            // cout<<"mid is "<<nums.at(mid)<<endl;
            if (nums.at(mid) >= nums.at(low)) {
                low = mid + 1;
                if (low <= len - 1 && nums.at(low) < nums.at(mid)) {
                    return nums.at(low);
                }
            } else {
                high = mid - 1;
                if (high >= 0 && nums.at(high) > nums.at(mid)) {
                    return nums.at(mid);
                }
            }
        }
        return nums.at(low);
    }
};
