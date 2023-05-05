// leetcode.com/problems/n-ary-tree-preorder-traversal/

#include <vector>

using std::vector;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> ans;

    void traversal(Node *node)
    {
        if (!node)
        {
            return;
        }
        ans.push_back(node->val);
        for (auto child : node->children)
        {
            traversal(child);
        }
    }

    vector<int> preorder(Node *root)
    {
        if (root)
        {
            traversal(root);
        }
        return ans;
    }
};

vector<int> preorder(Node *root)
{
    vector<int> ans;

    if (root)
    {
        ans.push_back(root->val);
        for (auto node : root->children)
        {
            if (node)
            {
                vector<int> tmp = preorder(node);
                for (int j : tmp)
                {
                    ans.push_back(j);
                }
            }
        }
    }

    return ans;
}

int main()
{
}