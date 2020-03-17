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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> v;

		if (root == NULL)
			return v;

		solve(root, "", v);

		return v;
	}

	void solve(TreeNode* node, string str, vector<string>& v) {
		if (node->left == NULL && node->right == NULL) {
			v.push_back(str + to_string(node->val));
			return;
		}

		if (node->left != NULL) {
			solve(node->left, str + to_string(node->val) + "->", v);
		}

		if (node->right != NULL) {
			solve(node->right, str + to_string(node->val) + "->", v);
		}
	}
};