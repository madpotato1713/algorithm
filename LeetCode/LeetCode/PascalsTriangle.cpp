class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;

		for (int y = 0; y < numRows; y++) {
			vector<int> input(y + 1, 1);
			for (int x = 1; x < y; x++) {
				input[x] = res[y - 1][x - 1] + res[y - 1][x];
			}
			res.push_back(input);
		}

		return res;
	}
};