/* CASE1 */
class Solution {
public:
	bool isPalindrome(string s) {
		string str;
		for (int i = 0; i < s.size(); i++) {
			char ch = s[i];
			if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
				str += tolower(ch);
			}
			else if (ch >= '0' && ch <= '9') {
				str += ch;
			}
		}

		int left = 0;
		int right = str.size() - 1;

		while (left < right) {
			if (str[left] != str[right])
				return false;

			left++;
			right--;
		}

		return true;
	}
};

/* CASE2 */
class Solution {
public:
	bool isPalindrome(string s) {
		int left = 0;
		int right = s.size() - 1;

		while (left < right) {
			char lc = tolower(s[left]);
			char rc = tolower(s[right]);


			if (!((lc >= 'a' && lc <= 'z') || (lc >= '0' && lc <= '9'))) {
				left++;
			}
			else if (!((rc >= 'a' && rc <= 'z') || (rc >= '0' && rc <= '9'))) {
				right--;
			}
			else {
				if (lc != rc)
					return false;
				left++;
				right--;
			}
		}

		return true;
	}
};

