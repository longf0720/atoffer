/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 
 
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode *> q;
        TreeNode *curr = root, *last = root, *nlast = root;
        vector<int> level;
        while(true) {
            if(q.empty()) {
                q.push(curr);
                nlast = curr;
            } else {
                curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left) {
                    q.push(curr->left);
                    nlast = curr->left;
                }
                if(curr->right) { 
                    q.push(curr->right);
                    nlast = curr->right;
                }
                if(last == curr) {
                    ans.push_back(level);
                    level.clear();
                    last = nlast;
                }
            }
            if(q.empty()) break;
        }
        return ans;
    }
};
