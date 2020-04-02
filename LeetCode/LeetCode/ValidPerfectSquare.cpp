class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num == 1)
			return true;

		long start = 0, end = num;
		long mid;

		while (start < end) {
			mid = (start + end) / 2;
			long val = mid * mid;

			if (mid == start || mid == end)
				return false;

			if (val == num)
				return true;

			if (val > num) {
				end = mid;
			}
			else if (val < num) {
				start = mid;
			}
		}

		return false;
	}
};