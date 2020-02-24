/* CASE1 */
class Solution {
public:
	int trailingZeroes(int n) {
		int res = 0;

		for (long i = 5, j = 1; i <= n; i += 5, j++) {
			if (j == 5) {
				j = 0;  //ÃÊ±âÈ­

				int num = i;
				while (num > 0 && num % 5 == 0) {
					res++;
					num /= 5;
				}
			}
			else {
				res++;
			}
		}

		return res;
	}
};

/* CASE2 */
class Solution {
public:
	int trailingZeroes(int n) {
		if (n == 0) return 0;

		return (n / 5) + trailingZeroes(n / 5);
	}
};