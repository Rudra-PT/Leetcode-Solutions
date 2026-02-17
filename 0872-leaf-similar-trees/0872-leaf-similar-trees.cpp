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
class Solution 
{
public:
    void leaf(TreeNode* root,vector<int>& leaves)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL)
        {
            leaves.push_back(root->val);
        }
        leaf(root->left,leaves);
        leaf(root->right,leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> leaves1,leaves2;

        leaf(root1,leaves1);
        leaf(root2,leaves2);

        return leaves1==leaves2;
    }
};