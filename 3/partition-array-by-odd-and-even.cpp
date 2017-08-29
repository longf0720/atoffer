class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        int sz = nums.size();
        int low = 0, high = sz - 1;
        while(low < high) {
            //search even from begin
            while(nums[low] % 2 != 0) {
                low++;
                if(low >= high) break;
            }
            //search odd from end
            while(nums[high] % 2 == 0) {
                high--;
                if(high <= low) break;
            }
            //swap odd and even
            if(low < high)
                swap(nums[low], nums[high]);
            low++;
            high--;
        }
    }
};
