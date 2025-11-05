#include <bits/stdc++.h>
using namespace std;

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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;  // track the direction of traversal

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // find correct position based on direction
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(level);
            leftToRight = !leftToRight;  // flip direction for next level
        }

        return ans;
    }
};

int main()
{
    // Create a sample binary tree:
    //         3
    //        / \
    //      9    20
    //          /  \
    //         15   7 

    TreeNode *root = new TreeNode(3);
    root->right = new TreeNode(20);
    root->left = new TreeNode(9);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);
    for(vector<int> ans1:result ){
        for(int ans2:ans1){
            cout<<ans2<<" ";
        }
        cout<<endl;
    }



    // Clean up memory (optional but good practice)
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
    