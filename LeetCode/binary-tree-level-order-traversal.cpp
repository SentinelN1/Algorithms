// leetcode.com/problems/binary-tree-level-order-traversal/

#include <queue>

using std::queue;
using std::vector;

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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;

    if (root)
    {
        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            int n = nodes.size();
            vector<int> level;
            for (int i = 0; i < n; i++)
            {
                auto cur = nodes.front();
                level.push_back(cur->val);
                nodes.pop();
                if (cur->left)
                {
                    nodes.push(cur->left);
                }
                if (cur->right)
                {
                    nodes.push(cur->right);
                }
            }
            ans.push_back(level);
        }
    }

    return ans;
}
