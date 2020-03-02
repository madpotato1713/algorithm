class Solution {
public:
	unordered_map<int, int> um;

	bool isHappy(int n) {
		if (n == 1) return true;
		if (um[n] > 1) return false;

		int res = 0;
		while (n > 0) {
			res += pow((n % 10), 2);
			n /= 10;
		}

		um[res]++;
		return isHappy(res);
	}
};