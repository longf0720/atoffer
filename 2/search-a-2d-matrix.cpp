class Solution {
public:
    /*返回第一个大于target值的下标*/
    int searchRow(vector<int> sortedArray, int target) {
        int size = sortedArray.size();
        if (size > 0) {
            int low = 0, high = size - 1;
            if (target > sortedArray.at(high))
                return size;
            if (target < sortedArray.at(low))
                return low;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (target == sortedArray.at(mid)) {
                    return mid + 1;
                }
                else if (target < sortedArray.at(mid)) {
                    high = mid - 1;
                    if (high >= 0 && sortedArray.at(high) < target)
                        return mid;
                }
                else {
                    low = mid + 1;
                    if (low < size && sortedArray.at(low) > target)
                        return low;
                }
            }
        }
        return -1;
    }
    /*二分查找*/
    int binarySearch(vector<int> sortedArray, int target) {
        int size = sortedArray.size();
        int low = 0, high = size - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (target == sortedArray.at(mid)) {
                return mid;
            }
            else if (target < sortedArray.at(mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
    }
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int row = matrix.size();
        if (row > 0) {
            vector<int> yMatrix;
            for (int i = 0; i < row; i++) {
                //cout<<"the %dth row's first element is "<<matrix.at(i).at(0)<<endl;
                yMatrix.push_back(matrix.at(i).at(0));
            }
            int xLoc = searchRow(yMatrix, target);
            if (xLoc != 0 && binarySearch(matrix.at(xLoc-1), target) != -1) {
                return true;
            } else {
                return false;
            }
        }
        return false;

    }

    bool searchMatrix_easy(vector<vector<int>> matrix, int target) {
        vector<int> v;
        for(auto i : matrix) {
            for(auto j : i) {
                v.push_back(j);
            }
        }
        int loc = binarySearch(v, target);
        if(loc != -1) return true;
        else return false;
    }
};

