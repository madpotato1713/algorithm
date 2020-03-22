/* CASE1 */
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != i) {
				return i;
			}
		}

		return nums[nums.size() - 1] + 1;
	}
};

/* CASE2 */
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int res = nums.size();

		for (int i = 0; i < nums.size(); i++) {
			res ^= nums[i];
			res ^= i;
		}

		return res;
	}
};