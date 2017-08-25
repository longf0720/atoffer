class Solution {
public:
    /*返回第一个大于target值的下标*/
    int binarySearch(vector<int> sortedArray, int target) {
        int size = sortedArray.size();
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
        return -1;
    }
    /**
    * @param matrix: A list of lists of integers
    * @param target: An integer you want to search in matrix
    * @return: An integer indicate the total occurrence of target in the given matrix
    */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        int counter = 0;
        int row = matrix.size();
        if (row == 0) return 0;
        int xPos = binarySearch(matrix.at(0), target);
        //cout<<"xPos="<<xPos<<endl;
        vector<int> yMatrix;
        for (int i = 0; i < row; i++) {
            //cout<<"the %dth row's first element is "<<matrix.at(i).at(0)<<endl;
            yMatrix.push_back(matrix.at(i).at(0));
        }
        int yPos = binarySearch(yMatrix, target);
        //cout<<"yPos="<<yPos<<endl;
        for (int i = 0; i < yPos; i++) {
            for (int j = 0; j < xPos; j++) {
                if (target == matrix.at(i).at(j))
                    counter++;
            }
        }
        return counter;
    }
};

