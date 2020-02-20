class Solution {
public:
	string convertToTitle(int n) {
		n--;
		string res;

		while (n >= 0) {
			res += (n % 26 + 'A');
			n -= (n % 26);
			n /= 26;
			n--;
		}

		reverse(res.begin(), res.end());

		return res;
	}
};