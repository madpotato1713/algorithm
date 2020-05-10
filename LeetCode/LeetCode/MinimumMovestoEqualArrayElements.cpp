/* CASE1 */
class Solution {
public:
	int minMoves(vector<int>& nums) {

		int min = *min_element(nums.begin(), nums.end());

		int res = 0;
		for (auto n : nums) {
			res += (n - min);
		}

		return res;
	}
};

/* CASE2 */
class Solution {
public:
	int minMoves(vector<int>& nums) {

		long res = 0;
		int minimum = nums[0];
		for (auto n : nums) {
			res += n;
			minimum = min(minimum, n);
		}

		return res - minimum * nums.size();
	}
};

