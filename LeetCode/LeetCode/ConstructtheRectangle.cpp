/* CASE 1 */
class Solution {
public:
	vector<int> constructRectangle(int area) {
		int L = area, W = 1;

		for (int i = 2; i <= area / 2; i++) {
			if (area % i == 0) {
				if (abs(L - W) > abs((area / i) - i)) {
					L = area / i;
					W = i;
				}
			}
		}

		return L > W ? vector<int>{L, W} : vector<int>{ W, L };
	}
};

/* CASE 2 */
class Solution {
public:
	vector<int> constructRectangle(int area) {
		int L = area, W = 1;

		for (int i = 2; i <= area / 2; i++) {
			if (i >= L) break;
			if (area % i == 0) {
				if ((L - W) > ((area / i) - i)) {
					L = area / i;
					W = i;
				}
			}
		}

		return vector<int>{L, W};
	}
};
