class Solution {
public:
	string reverseVowels(string s) {
		string vowels = "aeiouAEIOU";

		int start = 0, end = s.size() - 1;

		while (start < end) {
			while (start < end) {
				if (vowels.find(s[start]) != string::npos) {
					break;
				}
				start++;
			}

			while (start < end) {
				if (vowels.find(s[end]) != string::npos) {
					break;
				}
				end--;
			}

			swap(s[start], s[end]);
			start++; end--;
		}

		return s;
	}
};

