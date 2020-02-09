/* CASE 1 */
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
		vector<vector<int>> res;

		if (root == NULL) return res;

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			int size = q.size();
			vector<int> v;

			for (int i = 0; i < size; i++) {
				TreeNode* front = q.front();
				q.pop();

				v.push_back(front->val);
				if (front->left != NULL)
					q.push(front->left);
				if (front->right != NULL)
					q.push(front->right);
			}

			res.push_back(v);
		}

		reverse(res.begin(), res.end());
		return res;
	}
};

/* CASE 2 */
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