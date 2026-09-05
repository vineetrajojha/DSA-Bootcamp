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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        collect(root1, v1);
        collect(root2, v2);
        return v1 == v2;
    }
private:
    void collect(TreeNode* node, vector<int>& v) {
        if (!node) return;
        if (!node->left && !node->right) {
            v.push_back(node->val);
            return;
        }
        collect(node->left, v);
        collect(node->right, v);
    }
};