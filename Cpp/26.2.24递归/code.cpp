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
    int f(TreeNode* x,int n){
        if(x == nullptr){
            return n;
        }else{
            TreeNode* left=x->left;
            TreeNode* right=x->right;
            if(right==nullptr && left == nullptr){
                return x->val+2*n;
            }else if(right == nullptr){
                return f(left,x->val+2*n);
            }else if(left == nullptr){
                return f(right,x->val+2*n);
            }else{
                return f(right,x->val+2*n)+f(left,x->val+2*n);
            }
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        return f(root,0);
    }
};