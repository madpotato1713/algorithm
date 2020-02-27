/* CASE1 */
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;

		for (int i = 0; i <= 31; i++) {
			uint32_t num = (n & (1 << i));

			int shift = 31 - 2 * i;
			if (shift >= 0) {
				num = (num << shift);
			}
			else {
				num = (num >> -shift);
			}

			res += num;
		}

		return res;
	}
};

/* CASE2 */
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;

		for (int i = 0; i <= 31; i++) {
			int shift = 31 - 2 * i;
			if (shift >= 0) {
				res += ((n & (1 << i)) << shift);
			}
			else {
				res += ((n & (1 << i)) >> -shift);
			}
		}

		return res;
	}
};



/* CASE3 */
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		uint32_t mul = 1;

		for (int i = 0; i <= 15; i++) {
			res += ((n & mul) << (31 - 2 * i));
			mul *= 2;
		}

		for (int i = 16; i <= 31; i++) {
			res += ((n & mul) >> (2 * i - 31));
			mul *= 2;
		}

		return res;
	}
};