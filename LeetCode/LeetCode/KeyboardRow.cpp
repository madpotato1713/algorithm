/* CASE1 */
class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> res;
		unordered_map<char, int> um;
		um['q'] = um['w'] = um['e'] = um['r'] = um['t'] = um['y'] = um['u'] = um['i'] = um['o'] = um['p'] = 1;
		um['Q'] = um['W'] = um['E'] = um['R'] = um['T'] = um['Y'] = um['U'] = um['I'] = um['O'] = um['P'] = 1;
		um['a'] = um['s'] = um['d'] = um['f'] = um['g'] = um['h'] = um['j'] = um['k'] = um['l'] = 2;
		um['A'] = um['S'] = um['D'] = um['F'] = um['G'] = um['H'] = um['J'] = um['K'] = um['L'] = 2;
		um['z'] = um['x'] = um['c'] = um['v'] = um['b'] = um['n'] = um['m'] = 3;
		um['Z'] = um['X'] = um['C'] = um['V'] = um['B'] = um['N'] = um['M'] = 3;

		for (int i = 0; i < words.size(); i++) {
			int val = um[words[i][0]];
			for (int j = 1; j < words[i].size(); j++) {
				if (val != um[words[i][j]]) {
					val = 0;
					break;
				}
			}
			if (val) {
				res.push_back(words[i]);
			}
		}

		return res;
	}
};

/* CASE2 */
class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> res;
		unordered_map<char, int> um;
		um['q'] = um['w'] = um['e'] = um['r'] = um['t'] = um['y'] = um['u'] = um['i'] = um['o'] = um['p'] = 1;
		um['a'] = um['s'] = um['d'] = um['f'] = um['g'] = um['h'] = um['j'] = um['k'] = um['l'] = 2;
		um['z'] = um['x'] = um['c'] = um['v'] = um['b'] = um['n'] = um['m'] = 3;

		for (int i = 0; i < words.size(); i++) {
			char ch1 = words[i][0];
			if (!(ch1 >= 'a' && ch1 <= 'z')) {
				ch1 = ch1 - 'A' + 'a';
			}
			int val = um[ch1];
			for (int j = 1; j < words[i].size(); j++) {
				char ch2 = words[i][j];
				if (!(ch2 >= 'a' && ch2 <= 'z')) {
					ch2 = ch2 - 'A' + 'a';
				}
				if (val != um[ch2]) {
					val = 0;
					break;
				}
			}
			if (val) {
				res.push_back(words[i]);
			}
		}

		return res;
	}
};

