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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		int depth = depthCalc(root);

		vector<vector<int>> res(depth);

		addVal(res, root, depth - 1);

		return res;
	}

	int depthCalc(TreeNode* node) {
		if (node == NULL) return 0;

		return max(depthCalc(node->left), depthCalc(node->right)) + 1;
	}

	void addVal(vector<vector<int>>& res, TreeNode* node, int depth) {
		if (node == NULL) return;

		addVal(res, node->left, depth - 1);
		addVal(res, node->right, depth - 1);

		res[depth].push_back(node->val);
	}
};