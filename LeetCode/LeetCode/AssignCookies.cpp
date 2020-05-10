/* CASE1 */
class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		if (g.size() == 0 || s.size() == 0) return 0;

		sort(g.begin(), g.end());

		priority_queue<int> pq;
		int m = s[0];
		for (auto n : s) {
			if (n >= g[0]) {
				pq.push(-n);
			}
			m = max(m, n);
		}

		int res = 0;
		vector<int>::iterator itr = g.begin();
		while (!pq.empty()) {
			int top = -pq.top();
			pq.pop();

			if (itr == g.end() || *itr > m)
				break;

			if (top >= *itr) {
				itr++;
				res++;
			}
		}

		return res;
	}
};

/* CASE2 */
class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		int i = 0, j = 0;
		while (i < g.size() && j < s.size()) {
			if (g[i] <= s[j]) {
				i++;
			}
			j++;
		}

		return i;
	}
};