class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";

		string res = "";
		int size = strs[0].size();

		for (int j = 0; j < size; j++) {
			bool flag = true;
			char word = strs[0][j];

			for (int i = 1; i < strs.size(); i++) {
				if (strs[i].size() <= j) {
					flag = false;
					break;
				}
				if (strs[i][j] != word) {
					flag = false;
					break;
				}
			}

			if (flag) {
				res += word;
			}
			else {
				break;
			}
		}


		return res;
	}
};