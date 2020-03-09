class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> um;

		for (int i = 0; i < nums.size(); i++) {
			if (um[nums[i]] > 0)
				return true;
			else
				um[nums[i]]++;
		}

		return false;
	}
};