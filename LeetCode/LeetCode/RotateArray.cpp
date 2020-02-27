/* CASE 1 */
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();

		queue<int> q;
		for (int i = nums.size() - k; i < nums.size(); i++)
			q.push(nums[i]);

		for (int i = nums.size() - 1; i >= k; i--) {
			nums[i] = nums[i - k];
		}

		int idx = 0;
		while (!q.empty()) {
			nums[idx] = q.front();
			q.pop();
			idx++;
		}
	}
};

/* CASE2 */
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		for (int i = 0; i < nums.size() - k; i++) {
			nums.push_back(nums[0]);
			nums.erase(nums.begin());
		}
	}
};

/* CASE 3 */
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		vector<int> copy(nums);

		int size = nums.size();
		for (int i = 0; i < size; i++) {
			nums[(i + k) % size] = copy[i];
		}
	}
};