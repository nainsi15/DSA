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
    vector<int> postorderTraversal(TreeNode* root) {
          stack<TreeNode*> st;
            vector<int> arr;
            if(root == NULL) return arr;
            st.push(root);
            
            while(st.empty() == false){
               root = st.top();
               st.pop();
               arr.push_back(root->val);

                if(root->left != NULL){
                st.push(root->left);
               }
               if(root->right != NULL){
                st.push(root->right);
               }
            }

            reverse(arr.begin(), arr.end());
            return arr;
    }
};