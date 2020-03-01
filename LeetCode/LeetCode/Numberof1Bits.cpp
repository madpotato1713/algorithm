class Solution {
public:
	int hammingWeight(uint32_t n) {
		int res = 0;
		uint32_t num = 1;

		for (int i = 0; i < 32; i++) {
			if (num & n)
				res++;
			num *= 2;
		}

		return res;
	}
};