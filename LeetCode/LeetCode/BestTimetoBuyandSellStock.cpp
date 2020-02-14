/* CASE1 */
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size = prices.size();
		int res = 0;

		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				res = max(res, prices[j] - prices[i]);
			}
		}

		return res;
	}
};


/* CASE2 */
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int res = 0;
		int size = prices.size();
		if (!size) return res;

		int minNum = prices[0];
		for (int i = 1; i < size; i++) {
			if (prices[i] < minNum) {
				minNum = prices[i];
			}
			else if (prices[i] > minNum) {
				res = max(res, prices[i] - minNum);
			}
		}

		return res;
	}
};