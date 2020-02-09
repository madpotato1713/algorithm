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
	bool isBalanced(TreeNode* root) {
		return treeHeight(root) != -1;
	}

	int treeHeight(TreeNode* node) {
		if (node == NULL) return 0;

		int left = treeHeight(node->left);
		int right = treeHeight(node->right);

		if (abs(left - right) > 1 || left == -1 || right == -1) return -1;

		return max(left, right) + 1;
	}
};