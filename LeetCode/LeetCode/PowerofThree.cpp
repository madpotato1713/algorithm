/* CASE1 */
class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n % 2 == 0 || n < 0)
			return false;

		while (n > 3) {
			if (n % 3 != 0)
				return false;
			n /= 3;

			if (n % 2 == 0)
				return false;
		}

		return (n % 3 == 0 || n == 1);
	}
};

/* CASE2 */
class Solution {
public:
	bool isPowerOfThree(int n) {
		return fmod(log10(n) / log10(3), 1) == 0;
	}
};