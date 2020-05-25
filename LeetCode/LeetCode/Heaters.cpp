class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());

		int res = 0;
		int j = 0;
		for (int i = 0; i < houses.size(); i++) {
			int dist = numeric_limits<int>::max();
			for (; j < heaters.size(); j++) {
				int nextDist = abs(houses[i] - heaters[j]);

				if (dist < nextDist) {
					break;
				}

				dist = nextDist;
			}
			if (j > 0) j--;
			res = max(res, dist);
		}

		return res;
	}
};