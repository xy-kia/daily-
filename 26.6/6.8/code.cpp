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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, bool> isRoot;
        unordered_map<int, TreeNode*> nodes;
        for(const auto& d: descriptions) {
            int p = d[0];
            int c = d[1];
            bool left = d[2];
            if(!isRoot.count(p)) {
                isRoot[p] = true;
            }
            isRoot[c] = false;
            if(!nodes.count(p)){
                nodes[p] = new TreeNode(p);
            }
            if(!nodes.count(c)){
                nodes[c] = new TreeNode(c);
            }
            if(left){
                nodes[p]->left = nodes[c];
            }else{
                nodes[p]->right = nodes[c];
            }
        }
        int root = -1;
        for(const auto& [val,r]: isRoot){
            if(r){
                root = val;
                break;
            }
        }   
        return nodes[root];
    }
};