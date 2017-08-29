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
private:
    int findRootInInOrder(int root_val, vector<int> inorder) {
        int sz = inorder.size();
        for(int i = 0; i < sz; i++) {
            if(inorder[i] == root_val) {
                return i;
            }
        }
        return -1;
    }
    /**
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(postorder.size() == 0) return NULL;
        int root_val = postorder.back();
        TreeNode *root = new TreeNode(root_val);
        TreeNode *left  = NULL, *right = NULL; 
        vector<int> left_in, left_post;
        vector<int> right_in, right_post;
        
        int index = findRootInInOrder(root_val, inorder);
        if(-1 == index) {
            return NULL; //异常
        }
        for(int i = 0; i < index; i++) {
            left_in.push_back(inorder[i]);
        }
        for(int i = index + 1; i < inorder.size(); i++) {
            right_in.push_back(inorder[i]);
        }

        for(int i = 0; i < left_in.size(); i++) {
            left_post.push_back(postorder[i]);
        }
        for(int i = left_in.size(); i < postorder.size() -1; i++) {
            right_post.push_back(postorder[i]);
        }
        
        left = buildTree(left_in, left_post);
        right = buildTree(right_in, right_post);
        
        root->left  = left;
        root->right = right;
        return root;
    }
};
