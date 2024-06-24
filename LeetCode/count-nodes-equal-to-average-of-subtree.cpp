// leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

#include <vector>

using std::pair;

struct NodeData
{
    int sum;
    int num;
    int count;
};

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

class Solution
{
public:
    NodeData SubTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {0, 0, 0};
        }

        NodeData left = SubTree(root->left);
        NodeData right = SubTree(root->right);
        int sum = left.sum + right.sum + root->val;
        int num = left.num + right.num + 1;
        int count = left.count + right.count + (sum / num == root->val);
        return {sum, num, count};
    }

    int averageOfSubtree(TreeNode *root)
    {
        return SubTree(root).count;
    }
};

int main()
{
    Solution sol;
    auto p = sol.SubTree(nullptr);
    return 0;
}