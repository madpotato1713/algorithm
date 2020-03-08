/* CASE1 */
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int slen = s.size();
		int tlen = t.size();
		if (slen != tlen) return false;

		unordered_map<char, int> sm, tm;
		int scnt = 1, tcnt = 1;
		string sres, tres;

		for (int i = 0; i < slen; i++) {
			int& sint = sm[s[i]];
			if (!sint) {
				sres += (scnt + '0');
				sint = scnt;
				scnt++;
			}
			else {
				sres += sint;
			}

			int& tint = tm[t[i]];
			if (!tint) {
				tres += (tcnt + '0');
				tint = tcnt;
				tcnt++;
			}
			else {
				tres += tint;
			}

			if (sres[i] != tres[i])
				return false;
		}

		return true;
	}
};

/* CASE2 */
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> sm, tm;
		int len = s.size();

		for (int i = 0; i < len; i++) {
			sm[s[i]] = t[i];
			tm[t[i]] = s[i];
		}

		for (int i = 0; i < len; i++) {
			if (sm[s[i]] != t[i] || tm[t[i]] != s[i])
				return false;
		}

		return true;
	}
};