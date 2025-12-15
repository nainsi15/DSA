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
     TreeNode *build(vector<int> & preorder, int & i, int bound){
        // If all elements are used or the next element
        // is greater than the bound, return null
        if( i == preorder.size() || preorder[i] > bound){
            return NULL;
        }
        // create a new node
        TreeNode* root = new TreeNode(preorder[i++]);
        //recursively construct the left subtree with curr value as the new node
        root->left = build(preorder, i , root->val);
         // Recursively construct the right subtree with the same bound as the parent's bound
        root->right = build(preorder, i , bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int  i = 0;
        return build(preorder, i , INT_MAX);
    }
};