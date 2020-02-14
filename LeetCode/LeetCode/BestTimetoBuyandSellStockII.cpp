class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int res = 0;
		int sum = 0;

		int size = prices.size();
		if (!size) return res;

		int fst, snd;
		fst = snd = prices[0];

		for (int i = 1; i < size; i++) {
			if (snd > prices[i]) {
				snd = prices[i];
			}

			if (fst > prices[i]) {
				fst = prices[i];
				sum += res;
				res = 0;
			}
			else {
				res = max(prices[i] - fst, res + prices[i] - snd);
				snd = prices[i];
			}
		}
		if (res) sum += res;

		return sum;
	}
};