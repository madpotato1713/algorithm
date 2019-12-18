class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if (!size) return 0;

		int num = nums[0];
		int idx = 1;
		for (int i = 1; i < size; i++) {
			if (nums[i] != num) {
				nums[idx] = num = nums[i];
				idx++;
			}
		}

		return idx;
	}
};