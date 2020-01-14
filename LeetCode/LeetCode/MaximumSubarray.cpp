//case1
class Solution {
public:
	vector<int> cache;

	int maxNum(vector<int>& nums, int idx) {
		//base case
		if (idx == nums.size()) return 0;

		int& res = cache[idx];
		if (res != -1) return res;

		res = max(nums[idx], nums[idx] + maxNum(nums, idx + 1));

		return res;
	}

	int maxSubArray(vector<int>& nums) {

		//cache initialize;
		cache.resize(nums.size(), -1);
		maxNum(nums, 0);
		sort(cache.begin(), cache.end(), greater<int>());

		return cache[0];
	}
};

//case2
class Solution {
public:
	vector<int> cache;

	int maxNum(vector<int>& nums, int idx) {
		//base case
		if (idx == nums.size() - 1) return nums[idx];

		int& res = cache[idx];
		if (res != -1) return res;

		res = max(nums[idx], nums[idx] + maxNum(nums, idx + 1));

		return res;
	}

	int maxSubArray(vector<int>& nums) {

		//cache initialize;
		cache.resize(nums.size(), -1);

		int res = numeric_limits<int>::min();
		for (int i = 0; i < nums.size(); i++) {
			res = max(res, maxNum(nums, i));
		}

		return res;
	}
};


//case3
class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		int maxNum = numeric_limits<int>::min();

		for (int i = 0; i < nums.size(); i++) {
			int sum = 0;
			for (int j = i; j < nums.size(); j++) {
				sum += nums[j];
				maxNum = max(maxNum, sum);
			}
		}

		return maxNum;
	}
};