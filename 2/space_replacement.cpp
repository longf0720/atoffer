class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        if (string == NULL || length <= 0) {
            return 0;
        }
        int spaceCount = 0;
        for (int i = 0; i < length; i++) {
            if (string[i] == ' ') {
                spaceCount++;
            }
        }
        int new_len = length + 2 * spaceCount;
        for (int i = length - 1, j = new_len - 1; i >= 0; i--) {
            if (string[i] != ' ') {
                string[j] = string[i];
                j--;
            } else {
                string[j] = '0';
                string[j - 1] = '2';
                string[j -2 ] = '%';
                j -= 3;
            }
        }
        return new_len;
    }
};
