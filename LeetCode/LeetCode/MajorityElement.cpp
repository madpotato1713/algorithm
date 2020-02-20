class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int maj = (nums.size() - 1) / 2;
		unordered_map<int, int> um;

		for (auto num : nums) {
			if (++um[num] > maj)
				return num;
		}

		return 0;
	}
};