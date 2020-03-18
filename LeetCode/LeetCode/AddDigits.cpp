/* CASE1 */
class Solution {
public:
	int addDigits(int num) {
		while (num >= 10) {
			num = (num / 10 + num % 10);
		}

		return num;
	}
};

/* CASE2 */
class Solution {
public:
	int addDigits(int num) {
		if (num < 10)
			return num;

		if (!(num % 9))
			return 9;

		return num % 9;
	}
};