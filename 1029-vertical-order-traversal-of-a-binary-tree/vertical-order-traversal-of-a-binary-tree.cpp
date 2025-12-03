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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector<vector<int>> result;             // final answer list

        if (root == nullptr) {
            return result;                      // empty tree → return empty
        }

        // map: x → (y → min-heap of values)
        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> nodesMap;

        // queue for BFS: store node + its x,y positions
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});                 // root at (x=0, y=0)

        while (!q.empty()) {                    // BFS loop
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;           // current node
            int x = p.second.first;             // vertical column
            int y = p.second.second;            // depth level

            nodesMap[x][y].push(node->val);    // store value at (x,y)

            if (node->left) {                   // left child → x - 1
                q.push({node->left, {x - 1, y + 1}});
            }

            if (node->right) {                  // right child → x + 1
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        // Build the output from the map
        for (auto& p : nodesMap) {              // loop over x columns (sorted)
            vector<int> column;

            for (auto& q : p.second) {          // loop over y levels (sorted)
                while (!q.second.empty()) {     // pop all values (sorted)
                    column.push_back(q.second.top());
                    q.second.pop();
                }
            }

            result.push_back(column);           // add column to answer
        }

        return result;
    }
};