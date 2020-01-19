class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.size() == 0) return 0;

		int start = -1, end = -1;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (end == -1 && s[i] != ' ') {
				end = i;
			}
			else if (end != -1 && s[i] == ' ') {
				start = i;
				break;
			}
		}

		return end - start;
	}
};