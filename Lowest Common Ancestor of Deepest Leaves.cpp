// Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.
// Recall that:
// The node of a binary tree is a leaf if and only if it has no children
// The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
// The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.

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
    pair<int, TreeNode*> helper(TreeNode* node) {
        if (!node) return {0, nullptr};

        auto left = helper(node->left);
        auto right = helper(node->right);

        if (left.first == right.first)
            return {left.first + 1, node};
        else if (left.first > right.first)
            return {left.first + 1, left.second};
        else
            return {right.first + 1, right.second};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root, int* depth=NULL, int level=0) {
       return helper(root).second;
    }
};
