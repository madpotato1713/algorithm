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
