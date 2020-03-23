class Solution {
public:
	bool wordPattern(string pattern, string str) {
		string p1, p2;
		unordered_map<char, int> um1;
		unordered_map<string, int> um2;

		int val = 1;
		for (int i = 0; i < pattern.size(); i++) {
			if (um1[pattern[i]] == 0) {
				um1[pattern[i]] = val;
				val++;
			}
			p1 += to_string(um1[pattern[i]]);
		}

		val = 1;
		for (int i = 0; i < str.size(); i++) {
			string s;
			while (i < str.size() && str[i] != ' ') {
				s += str[i];
				i++;
			}
			if (um2[s] == 0) {
				um2[s] = val;
				val++;
			}
			p2 += to_string(um2[s]);
		}

		return p1 == p2;
	}
};