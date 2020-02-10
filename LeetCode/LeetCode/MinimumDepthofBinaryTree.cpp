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
	int minDepth(TreeNode* root) {
		if (root == NULL) return 0;

		return solve(root);
	}

	int solve(TreeNode* node) {
		if (node->left == NULL && node->right == NULL) return 1;

		int res = numeric_limits<int>::max();

		if (node->left != NULL)
			res = min(res, solve(node->left));
		if (node->right != NULL)
			res = min(res, solve(node->right));

		return res + 1;
	}
};