/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		invert(root);

		return root;
	}

	void invert(TreeNode* node) {
		if (node == NULL) return;

		TreeNode* left = node->left;
		TreeNode* right = node->right;

		node->left = right;
		node->right = left;

		invert(node->left);
		invert(node->right);
	}
};