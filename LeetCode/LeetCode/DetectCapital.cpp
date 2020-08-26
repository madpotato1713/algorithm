class Solution {
public:
	bool detectCapitalUse(string word) {
		if (case1(word)) {
			return true;
		}

		if (case2(word)) {
			return true;
		}

		if (case3(word)) {
			return true;
		}

		return false;
	}

	bool case1(string word) {
		for (char w : word) {
			if (w < 'A' || w > 'Z') {
				return false;
			}
		}
		return true;
	}

	bool case2(string word) {
		for (char w : word) {
			if (w < 'a' || w > 'z') {
				return false;
			}
		}
		return true;
	}

	bool case3(string word) {
		if (word[0] < 'A' || word[0] > 'Z') {
			return false;
		}
		for (char w : word.substr(1)) {
			if (w < 'a' || w > 'z') {
				return false;
			}
		}
		return true;
	}
};