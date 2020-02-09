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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0) return NULL;

		TreeNode* root = new TreeNode(NULL);
		solve(nums, root, 0, nums.size() - 1);

		return root;
	}

	void solve(vector<int>& nums, TreeNode* node, int left, int right) {

		int mid = (left + right) / 2;
		node->val = nums[mid];

		if (left <= mid - 1) solve(nums, node->left = new TreeNode(NULL), left, mid - 1); //left
		if (right >= mid + 1) solve(nums, node->right = new TreeNode(NULL), mid + 1, right); //right
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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return solve(nums, 0, nums.size() - 1);
	}

	TreeNode* solve(vector<int>& nums, int left, int right) {
		if (left > right) return NULL;

		int mid = (left + right) / 2;
		TreeNode* node = new TreeNode(nums[mid]);

		node->left = solve(nums, left, mid - 1);
		node->right = solve(nums, mid + 1, right);

		return node;
	}
};