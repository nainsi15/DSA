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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;    // assign a 2D vector to store the answer
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);   //intitially insert the root in the queue
        bool flag = true; //intially it will go from right to left (true means right->left)
        while(q.empty() == false){   //when queue is not empty 
            int size = q.size();
            vector<int> level;    //declare an array name level to store at each level

            for(int i = 0; i <size; i++){
                root = q.front();
                q.pop();
                level.push_back(root->val);

                if(root->left != NULL) q.push(root->left);
                if(root->right != NULL) q.push(root->right);
            }
            if(flag == false){
                reverse(level.begin(), level.end());
            }
            ans.push_back(level);
            flag = !flag;   //alternatively set the flag so as to traverse from l->r and r->l
        }
        return ans;
    }
};