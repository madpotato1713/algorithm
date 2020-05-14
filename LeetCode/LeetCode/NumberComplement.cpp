class Solution {
public:
	int findComplement(int num) {
		int res = 0;

		int i = 0;
		while (num > 0) {
			res += pow(2, i) * (num % 2 ? 0 : 1);
			num /= 2;
			i++;
		}

		return res;
	}
};