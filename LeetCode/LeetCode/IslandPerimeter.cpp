/* CASE1 */
class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int res = 0;

		int state;
		for (int y = 0; y < grid.size(); y++) {
			state = 0;
			for (int x = 0; x < grid[0].size(); x++) {
				if (grid[y][x] != state) {
					res++;
					state = grid[y][x];
				}
			}
			if (state)
				res++;
		}

		for (int x = 0; x < grid[0].size(); x++) {
			state = 0;
			for (int y = 0; y < grid.size(); y++) {
				if (grid[y][x] != state) {
					res++;
					state = grid[y][x];
				}
			}
			if (state)
				res++;
		}

		return res;
	}
};

/* CASE2 */
class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int res = 0;

		int h = grid.size();
		int w = grid[0].size();
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (grid[y][x] == 1) {
					//╩С, го, аб, ©Л
					if (y - 1 < 0 || grid[y - 1][x] == 0) res++;
					if (y + 1 >= h || grid[y + 1][x] == 0) res++;
					if (x - 1 < 0 || grid[y][x - 1] == 0) res++;
					if (x + 1 >= w || grid[y][x + 1] == 0) res++;
				}
			}
		}

		return res;
	}
};

