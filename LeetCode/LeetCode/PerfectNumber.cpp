class Solution {
public:
	bool checkPerfectNumber(int num) {
		if (num <= 2) return false;

		int sum = 1;
		for (int i = 2; i < pow(num, 0.5); i++) {
			if (num % i == 0) {
				sum += i;
				sum += (num / i);
			}
		}

		return (sum == num);
	}
};