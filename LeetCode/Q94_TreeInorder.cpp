#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(TreeNode *root, vector<int> &res)
    {
        if (root != NULL)
        {
            helper(root->left, res);
            res.push_back(root->val);
            helper(root->right, res);
        }
    }
};

int main()
{
    // Create a sample binary tree:
    //         1
    //          \
    //           2
    //          /
    //         3

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    // Clean up memory (optional but good practice)
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
    