/* CASE1 */
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		for (int i = 0; i < nums.size() - 1; i++) {
			for (int j = 0; j < nums.size() - 1 - i; j++) {
				if (nums[j] == 0) {
					swap(nums[j], nums[j + 1]);
				}
			}
		}
	}
};

/* CASE2 */
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int start = 0;
		int end = 1;
		int size = nums.size();

		while (start < end && start < size && end < size) {
			while (start < size) {
				if (nums[start] == 0)
					break;
				start++;
			}

			while (end < size) {
				if (end > start && nums[end] != 0)
					break;
				end++;
			}

			if (start < size && end < size)
				swap(nums[start], nums[end]);
		}
	}
};