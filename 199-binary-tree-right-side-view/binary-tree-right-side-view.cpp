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
private:
void func(TreeNode* root, vector<int> &res, int level){
    if(root == NULL) return;
    if(level == res.size()){
        res.push_back(root->val);
    }
    func(root->right, res, level+1);
    func(root->left , res, level+1);
}
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        func(root, res, 0);
        return res;
    }
};