class Solution {
public:
	int countSegments(string s) {
		int idx;
		int cnt = 0;

		while (1) {
			idx = s.find(" ");

			if (idx == string::npos)
				break;

			s = s.substr(idx + 1);
			if (idx != 0) {
				cnt++;
			}
		}

		if (s.size() > 0)
			cnt++;

		return cnt;
	}
};