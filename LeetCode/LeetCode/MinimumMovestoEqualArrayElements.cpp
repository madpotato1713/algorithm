/* CASE1 */
class Solution {
public:
	int minMoves(vector<int>& nums) {

		int res = 0;
		int minimum = nums[0];
		for (auto n : nums) {
			res += n;
			minimum = min(minimum, n);
		}

		return res - minimum * nums.size();
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

