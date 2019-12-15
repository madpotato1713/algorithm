class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;

		string str = to_string(x);
		int size = str.size();

		for (int i = 0; i < size / 2; i++) {
			if (str[i] != str[size - 1 - i]) return false;
		}

		return true;
	}
};