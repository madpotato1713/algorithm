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
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}

		int left = (root->left != NULL ? solve(root->left, 'l') : 0);
		int right = (root->right != NULL ? solve(root->right, 'r') : 0);

		return left + right;
	}

	int solve(TreeNode* node, char dir) {
		if (node->left == NULL && node->right == NULL) {
			if (dir == 'l') {
				return node->val;
			}
			if (dir == 'r') {
				return 0;
			}
		}

		int left = (node->left != NULL ? solve(node->left, 'l') : 0);
		int right = (node->right != NULL ? solve(node->right, 'r') : 0);

		return left + right;
	}
};
