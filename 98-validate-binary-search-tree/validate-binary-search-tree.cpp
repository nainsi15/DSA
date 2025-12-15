/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root , LONG_MIN, LONG_MAX);
    }
    bool isBST (TreeNode* root , long long min , long long max){
            // when  you reach last that means it's valid return true
            if(root == NULL) return true;   

            //if it is between the valid range or not 
            if(root->val >= max || root->val <= min ) return false;

            bool leftside = isBST(root->left, min , root->val);
            bool rightside = isBST(root->right , root->val, max);

            return leftside && rightside;
    }
};