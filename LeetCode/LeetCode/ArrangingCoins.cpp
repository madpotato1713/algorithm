/* CASE1 */
class Solution {
public:
	int arrangeCoins(int n) {
		int i = 1;
		while (n >= 0) {
			n -= i;
			i++;
		}

		return i - 2;
	}
};

/* CASE2 */
class Solution {
public:
	int arrangeCoins(int n) {
		return (sqrt(2.0 * n + 0.25) - 0.5);
	}
};