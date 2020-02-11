/* CASE1 */
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res(rowIndex + 1);
		res[0] = 1;

		for (int i = 1; i <= rowIndex; i++) {
			vector<int> tmp(res);
			for (int j = 1; j < i; j++) {
				res[j] = tmp[j - 1] + tmp[j];
			}
			res[i] = 1;
		}

		return res;
	}
};

/* CASE2 */
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res(rowIndex + 1, 0);
		res[0] = 1;

		for (int i = 1; i <= rowIndex; i++) {
			for (int j = i; j >= 1; j--) {
				res[j] = res[j] + res[j - 1];
			}
		}

		return res;
	}
};