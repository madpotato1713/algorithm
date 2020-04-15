class Solution {
public:
	int longestPalindrome(string s) {
		int alphabet[52] = { 0 };
		for (char ch : s) {
			if (ch >= 'A' && ch <= 'Z') {
				alphabet[ch - 'A' + 26]++;
			}
			else {
				alphabet[ch - 'a']++;
			}
		}

		int res = 0, odd = 0;
		for (int i = 0; i < 52; i++) {
			if (alphabet[i] % 2 == 0)
				res += alphabet[i];
			else {
				if (odd == 0) {
					odd = alphabet[i];
				}
				else if (odd < alphabet[i]) {
					res += (odd - 1);
					odd = alphabet[i];
				}
				else {
					res += (alphabet[i] - 1);
				}
			}
		}

		return res + odd;
	}
};