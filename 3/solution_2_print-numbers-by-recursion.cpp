class Solution {
private:
    vector<int> res;
    vector<int> s;

private:
    void transform(vector<int> &s, vector<int> &res) {
        int sz = s.size();
        int sum = 0;
        for(int i = 0; i < sz; i++) {
            sum += (pow(10, sz - i -1) * s[i]);
        }
        if(sum != 0) {
            res.push_back(sum);
        }
        s.pop_back();
    }
    void recur(int n, int len) {
        if(n > 0) {
            for(int i = 0; i <= 9; i++) {
                s.push_back(i);
                if(s.size() ==  len) {
                    transform(s, res);
                }
                recur(n-1, len);
            }
            s.pop_back();
        }
    }
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        recur(n, n);
        return res;
    }
};
