class Solution {
public:
	bool isUgly(int num) {
		if (num == 0)
			return false;

		while (!(num % 2)) {
			num /= 2;
		}
		if (num == 1)
			return true;

		while (!(num % 3)) {
			num /= 3;
		}
		if (num == 1)
			return true;

		while (!(num % 5)) {
			num /= 5;
		}
		if (num == 1)
			return true;

		return false;
	}
};