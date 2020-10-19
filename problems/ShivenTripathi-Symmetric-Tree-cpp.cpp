/**
 * Solution to 101. Symmetric Tree at LeetCode in <language>
 *
 * author: ShivenTripathi
 * ref: https://leetcode.com/problems/symmetric-tree/
 */
class Solution {
public:
    bool isTrue(TreeNode* left,TreeNode* right){
        if(!left&&!right)return true;
        if(!left||!right)return false;
     return left->val==right->val&&isTrue(left->right,right->left)&&isTrue(left->left,right->right);        
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;        
        return isTrue(root->left,root->right);
    }
};
