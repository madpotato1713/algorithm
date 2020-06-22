/* CASE1 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	static bool compare(pair<int, int> A, pair<int, int> B) {
		return A.second > B.second;
	}

	unordered_map<int, int> um;

	vector<int> findMode(TreeNode* root) {
		vector<pair<int, int>> v;
		vector<int> res;

		getMap(root);

		for (auto itr = um.begin(); itr != um.end(); itr++) {
			v.push_back(make_pair(itr->first, itr->second));
		}

		sort(v.begin(), v.end(), compare);

		int max;
		for (auto itr = v.begin(); itr != v.end(); itr++) {
			if (itr != v.begin() && itr->second < max) {
				break;
			}
			else {
				max = itr->second;
			}
			res.push_back(itr->first);
		}


		return res;
	}

	void getMap(TreeNode* node) {
		if (node == nullptr)
			return;

		um[node->val]++;

		getMap(node->left);
		getMap(node->right);
	}
};

/* CASE2 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

	unordered_map<int, int> um;

	vector<int> findMode(TreeNode* root) {
		priority_queue<pair<int, int>> pq;
		vector<int> res;

		getMap(root);

		for (auto itr = um.begin(); itr != um.end(); itr++) {
			pq.push(make_pair(itr->second, itr->first));
		}

		int max = 0;
		while (!pq.empty()) {
			pair<int, int> top = pq.top();
			pq.pop();

			if (!max)
				max = top.first;
			else if (max > top.first)
				break;

			res.push_back(top.second);
		}

		return res;
	}

	void getMap(TreeNode* node) {
		if (node == nullptr)
			return;

		um[node->val]++;

		getMap(node->left);
		getMap(node->right);
	}
};