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
    struct info {
        int h;
        bool ans;
        info (int h, bool ans) : h(h), ans(ans) {}
    };
    info DFS(TreeNode* cur) {
        if (cur == NULL) return info(0, true);
        info l = DFS(cur -> left), r = DFS(cur -> right);
        int h = max(l.h, r.h) + 1;
        bool ans = (abs(l.h - r.h) > 1 ? false : true) & l.ans & r.ans;
        return info(h, ans);
    }
    bool isBalanced(TreeNode* root) {
        return DFS(root).ans;
    }
};