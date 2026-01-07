#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct TreeNode
{
    int val;
    TreeNode *next;
    TreeNode() : val(0), next(nullptr) {}
    TreeNode(int x) : val(x), next(nullptr) {}
    TreeNode(int x, TreeNode *next) : val(x), next(next) {}
};

class Solution {
public:
long long mod = 1e9 + 7;
long long total = 0;
long long ans = 0;

    long long subTreeSum(TreeNode* root) {
        if(root == NULL)    return 0;

        long long leftSum = subTreeSum(root->left);
        long long rightSum = subTreeSum(root->right);

        ans = max(ans, (leftSum * (total - leftSum)));
        ans = max(ans, (rightSum * (total - rightSum)));

        return leftSum + rightSum + root->val;
    }

    void totalSum(TreeNode* root) {
        if(root == NULL)    return;
        total += root->val;
        totalSum(root->left);
        totalSum(root->right);
    }

    int maxProduct(TreeNode* root) {
        totalSum(root);
        subTreeSum(root);
        return ans % mod;
    }
};