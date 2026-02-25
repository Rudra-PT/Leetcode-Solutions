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
    bool helper(TreeNode* root , TreeNode*miniRoot){
        if(root == NULL && miniRoot == NULL){
            return true;
        }
        if(root == NULL || miniRoot == NULL){
            return false;
        }
        if(root->val != miniRoot->val){
            return false;
        }
        return helper(root->left , miniRoot->left) && helper(root->right , miniRoot->right);


    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot ==NULL) return false;
        if(root == NULL) return false;
        if(subRoot == NULL) return true;
        if( helper(root, subRoot)){
            return true;
        } 
        return isSubtree(root->left , subRoot) || isSubtree(root->right, subRoot);
    }
};