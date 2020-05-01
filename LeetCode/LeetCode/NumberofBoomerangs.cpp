class Solution {
public:
	int dist[500][500];

	int numberOfBoomerangs(vector<vector<int>>& points) {
		int len = points.size();
		if (len < 3) return 0;

		memset(dist, -1, sizeof(dist));

		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (dist[i][j] == -1) {
					int y = points[i][0] - points[j][0];
					int x = points[i][1] - points[j][1];

					dist[j][i] = dist[i][j] = (y * y + x * x);
				}
			}
		}

		int res = 0;
		for (int i = 0; i < len; i++) {
			unordered_map<int, int> um;
			for (int j = 0; j < len; j++) {
				if (i != j) {
					um[dist[i][j]]++;
				}
			}

			for (auto itr = um.begin(); itr != um.end(); itr++) {
				int cnt = itr->second;
				if (cnt >= 2) {
					res += (cnt * (cnt - 1));
				}
			}
		}

		return res;
	}
};