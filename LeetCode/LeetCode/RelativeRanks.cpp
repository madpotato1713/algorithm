class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		vector<string> res(nums.size());

		map<int, int, greater<int>> m;
		for (int i = 0; i < nums.size(); i++) {
			m[nums[i]] = i;
		}

		int cnt = 0;
		for (auto itr = m.begin(); itr != m.end(); itr++) {
			// res.push_back(to_string(itr->second));
			if (cnt < 3) {
				if (cnt == 0)
					res[itr->second] = "Gold Medal";
				else if (cnt == 1)
					res[itr->second] = "Silver Medal";
				else if (cnt == 2)
					res[itr->second] = "Bronze Medal";
			}
			else {
				res[itr->second] = to_string(cnt + 1);
			}
			cnt++;
		}

		return res;
	}
};