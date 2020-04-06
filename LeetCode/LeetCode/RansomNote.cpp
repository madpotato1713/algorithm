/* CASE1 */
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {

		for (int i = 0; i < ransomNote.size(); i++) {
			auto itr = magazine.find(ransomNote[i]);

			if (itr != string::npos) {
				magazine.erase(itr, 1);
			}
			else {
				return false;
			}
		}

		return true;
	}
};

/* CASE2 */
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int arr[26] = { 0 };

		for (int i = 0; i < magazine.size(); i++) {
			arr[magazine[i] - 'a']++;
		}

		for (int i = 0; i < ransomNote.size(); i++) {
			if (--arr[ransomNote[i] - 'a'] < 0)
				return false;
		}

		return true;
	}
};