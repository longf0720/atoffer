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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return NULL;
        } else if (preorder.size() != inorder.size()) {
            return NULL;
        } else {
            int root = preorder.at(0);
            // cout<<"root="<<root<<endl;
            // find root in inorder, and split it
            int l_node_counter = 0;
            for (auto item : inorder) {
                if (item == root) {
                    break;
                }
                l_node_counter++;
            }
            if (l_node_counter == preorder.size()) {
                // cann't find root in inorder
                // throw std::exception("Invalid Input");
                perror("Invalid input.");
                exit(-1);
            }
            // cout<<"node amount in left tree is:"<<l_node_counter<<endl;
            // build left Tree
            vector<int> l_preorder;
            vector<int> l_inorder;
            for (int i = 1; i <= l_node_counter; i++) {
                l_preorder.push_back(preorder.at(i));
            }
            for (int i = 0; i < l_node_counter; i++) {
                l_inorder.push_back(inorder.at(i));
            }
            TreeNode *lchild = buildTree(l_preorder, l_inorder);
            // build right Tree
            vector<int> r_preorder;
            vector<int> r_inorder;
            for (int i = l_node_counter + 1; i < preorder.size(); i++) {
                r_preorder.push_back(preorder.at(i));
            }
            for (int i = l_node_counter + 1; i < inorder.size(); i++) {
                r_inorder.push_back(inorder.at(i));
            }
            TreeNode *rchild = buildTree(r_preorder, r_inorder);
            // build root
            TreeNode *rootNode = new TreeNode(root);
            if (rootNode == NULL) {
                perror("new TreeNode failed, memory not enough");
            } else {
                rootNode->left = lchild;
                rootNode->right = rchild;
            }
            return rootNode;
        }
    }
};
