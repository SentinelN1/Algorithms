// leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include <cmath>

using std::max;
using std::min;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    int a = min(p->val, q->val);
    int b = max(p->val, q->val);

    if (b < root->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }

    if (root->val < a)
    {
        return lowestCommonAncestor(root->right, p, q);
    }

    return root;
}

int main()
{
}