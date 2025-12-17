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
class BSTIterator {
    stack< TreeNode*> stack;
public:
    //constructor
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    // return the next smallest num
    int next() {
        TreeNode *temp = stack.top();
        stack.pop();
        pushAll(temp->right);
        return temp->val;
    }
    //return true if there's next element in the iterator
    bool hasNext() {
        return !stack.empty();
    }
    	// push all the left nodes
    void pushAll(TreeNode* root){
        for(; root != NULL;){
            stack.push(root);
        root = root->left;
    }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */