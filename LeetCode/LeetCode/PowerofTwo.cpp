class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n != 1 && n % 2)
			return false;

		long num = 1;

		while (num < n) {
			num = num << 1;
		}

		return num == n;
	}
};