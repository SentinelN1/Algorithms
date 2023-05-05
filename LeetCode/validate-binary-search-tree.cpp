// leetcode.com/problems/validate-binary-search-tree/

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

int minInTree(TreeNode *root)
{
    int ans = root->val;

    if (root->left)
    {
        ans = min(ans, minInTree(root->left));
    }

    if (root->right)
    {
        ans = min(ans, minInTree(root->right));
    }

    return ans;
}

int maxInTree(TreeNode *root)
{
    int ans = root->val;

    if (root->left)
    {
        ans = max(ans, maxInTree(root->left));
    }

    if (root->right)
    {
        ans = max(ans, maxInTree(root->right));
    }

    return ans;
}

bool isValidBST(TreeNode *root)
{
    if (root->left)
    {
        if (!(maxInTree(root->left) < root->val && isValidBST(root->left)))
        {
            return false;
        }
    }

    if (root->right)
    {
        if (!(root->val < minInTree(root->right) && isValidBST(root->right)))
        {
            return false;
        }
    }

    return true;
}

int main()
{
}