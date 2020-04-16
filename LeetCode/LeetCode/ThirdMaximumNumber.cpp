class Solution {
public:
	int thirdMax(vector<int>& nums) {
		set<int, greater<int>> s;
		for (auto n : nums) {
			s.insert(n);
		}

		set<int>::iterator itr = s.begin();
		return s.size() < 3 ? *itr : *(++(++itr));
	}
};