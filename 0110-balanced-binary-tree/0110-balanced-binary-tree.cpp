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
    bool isBalanced(TreeNode* root) {

        return height( root ) != -1;
    }

    int height(TreeNode* node){

        if( node == NULL) return 0;

        int left_ht = height( node -> left);
        int right_ht = height( node -> right);

        if( left_ht == -1 || right_ht == -1) return -1;
        if( abs(left_ht - right_ht) > 1) return -1;

        return max(left_ht, right_ht) + 1;
    }
};