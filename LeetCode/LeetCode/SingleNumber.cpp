/* CASE1 */
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, int> um;

		for (int i = 0; i < nums.size(); i++) {
			um[nums[i]]++;
		}

		for (auto itr = um.begin(); itr != um.end(); itr++) {
			if (itr->second == 1) return itr->first;
		}

		return 0;
	}
};


/*CASE2*/
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;

		for (auto& num : nums) {
			res ^= num;
		}

		return res;
	}
};