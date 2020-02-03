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
	bool hasPathSum(TreeNode* root, int sum) {
		return solve(root, 0, sum);
	}

	bool solve(TreeNode* node, int acc, int sum) {
		if (node == NULL) return false;

		int nextAcc = acc + node->val;

		if (node->left == NULL && node->right == NULL) {
			return nextAcc == sum;
		}


		return solve(node->left, nextAcc, sum) || solve(node->right, nextAcc, sum);
	}
};