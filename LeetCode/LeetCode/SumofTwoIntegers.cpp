class Solution {
public:
	int getSum(int a, int b) {
		int sum;

		while (b) {
			sum = (a ^ b);
			b = (unsigned int)(a & b) << 1;
			a = sum;
		}

		return sum;
	}
};