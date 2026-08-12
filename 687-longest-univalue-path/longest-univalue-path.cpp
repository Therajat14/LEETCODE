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
    int maxLen = 0;
    pair<int, int> helper(TreeNode* root){
        if(!root) return {INT_MIN, 0};

        auto [le, lc] = helper(root->left);
        auto [re, rc] = helper(root->right);

        if(le == root->val && re == root->val) {
            maxLen = max(maxLen, lc + rc + 1);
            return {root->val, max(lc , rc) +  1};
        }
        if(le == root->val || re == root->val) {
            if(le == root->val){
                maxLen = max(maxLen, lc + 1);
                return { root->val, lc + 1};
            }
            else{
               maxLen = max(rc + 1, maxLen);
               return  { root->val, rc + 1};
            }
        }

        return {root->val, 1 };


    }
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
         return max(0, maxLen - 1);
    }
};