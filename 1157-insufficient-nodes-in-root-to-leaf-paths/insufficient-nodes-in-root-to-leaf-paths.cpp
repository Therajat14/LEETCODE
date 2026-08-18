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
    int maxSum = INT_MIN;
    int helper(TreeNode* root, int limit, int sum){
        if(!root) return INT_MIN;
        sum += root->val;

        if(!root->left && !root->right) return sum;

        int left = helper(root->left, limit , sum);
        int right = helper(root->right, limit, sum);

        if(left < limit) root->left = nullptr;
        if(right < limit) root->right = nullptr;

        maxSum = max(left, right);
        return max(left, right);
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        helper(root, limit, 0);
        if(maxSum < limit && root->val < limit) return nullptr;
        return root;
    }
};