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
    void collectInorder(TreeNode* root, vector<int>& vals) {
    if (root == nullptr)
        return;

    collectInorder(root->left, vals);  // 先遍历左子树
    vals.push_back(root->val);         // 访问根节点，存入值
    collectInorder(root->right, vals); // 再遍历右子树
    }
    TreeNode* buildBalancedBST(vector<int>& vals, int startIdx, int endIdx) {
    if (startIdx > endIdx)  // 递归终止条件：无元素可构建
        return nullptr;
    // 取中点（避免start+end溢出），作为当前子树的根节点值
    int middleIdx = startIdx + (endIdx - startIdx) / 2; 
    TreeNode* cur = new TreeNode(vals[middleIdx]);
    // 递归构建左子树：[start, middle-1]
    cur->left = buildBalancedBST(vals, startIdx, middleIdx - 1);
    // 递归构建右子树：[middle+1, end]
    cur->right = buildBalancedBST(vals, middleIdx + 1, endIdx);
    return cur;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        collectInorder(root, vals); // 步骤1：中序遍历提取有序值
        return buildBalancedBST(vals, 0, vals.size() - 1); // 步骤2：重构平衡树
    }
};