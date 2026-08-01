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
    vector<pair<int, TreeNode*>> hash;

    void inorder(TreeNode *root){
        if(!root) return;
        inorder(root->left);
        hash.push_back({root->val, root});
        inorder(root->right);
    }


    void recoverTree(TreeNode* root) {
        inorder(root);
        TreeNode * temp1 = nullptr;
        TreeNode * temp2 = nullptr;

        for(int i = 0; i < hash.size() - 1; i++){

            if(!(hash[i].first < hash[i + 1].first)){
                temp1 = hash[i].second;
                break;
            }
        }
        for(int i = hash.size() -1;  i  > 0 ; i--){

            if(!(hash[i].first > hash[i - 1].first)){
                temp2 = hash[i].second;
                break;
            }
        }

        int x = temp1->val;
        temp1->val = temp2->val;
        temp2->val = x;

    }
};