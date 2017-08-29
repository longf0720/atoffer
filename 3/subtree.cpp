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
public:
    bool isSame(TreeNode * T1, TreeNode * T2) {
        if(T1 == NULL && T2 == NULL) return true;
        else if (T1 != NULL && T2 == NULL) return false;
        else if (T1 == NULL && T2 != NULL) return false;
        if(T1->val == T2->val) {
            if(isSame(T1->left, T2->left)){
                if(isSame(T1->right, T2->right)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool next(TreeNode * T1, TreeNode * T2) {
        if(isSubtree(T1->left, T2)) {
            return true;
        } else if(isSubtree(T1->right, T2)) {
            return true;
        } else {
            return false;
        }
    }

    /*
     * @param T1: The roots of binary tree T1.
     * @param T2: The roots of binary tree T2.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode * T1, TreeNode * T2) {
        // write your code here
        if(T1 == NULL && T2 == NULL) return true;
        else if(T1 == NULL && T2 != NULL) return false;
        else if(T1 != NULL && T2 == NULL) return true;
        if(T1->val == T2->val) {
            if(isSame(T1, T2)) {
                return true;
            } else {
                return next(T1, T2);
            }
        } else {
            return next(T1, T2);
        }
    }
};
