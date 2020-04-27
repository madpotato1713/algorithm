/* CASE1 */
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
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return 0;

		int res = 0;

		vector<int> acc;
		solve(root, sum, acc, res);

		return res;
	}

	void solve(TreeNode* node, int sum, vector<int> acc, int& res) {
		if (node->val == sum) {
			res++;
		}

		for (int i = 0; i < acc.size(); i++) {
			if ((node->val + acc[i]) == sum) {
				res++;
			}
			acc[i] += (node->val);
		}
		acc.push_back(node->val);

		if (node->left != NULL) {
			solve(node->left, sum, acc, res);
		}
		if (node->right != NULL) {
			solve(node->right, sum, acc, res);
		}
	}
};

/* CASE2 */
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
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return 0;

		return solve(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}

	int solve(TreeNode* node, int sum) {
		if (node == NULL)
			return 0;

		int res = 0;
		if (node->val == sum)
			res++;

		res += solve(node->left, sum - node->val);
		res += solve(node->right, sum - node->val);

		return res;
	}
};