// case 1
class Solution {
public:
	int climbStairs(int n) {
		vector<int> cache(n + 1, 0);

		return solve(cache, n);
	}

	int solve(vector<int>& cache, int n) {
		if (n <= 1) return 1;

		if (cache[n] != 0) return cache[n];

		return cache[n] = (solve(cache, n - 1) + solve(cache, n - 2));
	}
};


// case 2
class Solution {
public:
	int climbStairs(int n) {
		vector<int> cache(n + 1);
		cache[0] = 1;
		cache[1] = 1;

		for (int i = 2; i <= n; i++) {
			cache[i] = cache[i - 1] + cache[i - 2];
		}

		return cache[n];
	}
};


// case 3
class Solution {
public:
	unordered_map<int, int> map;

	int climbStairs(int n) {
		map[0] = 1;
		map[1] = 1;

		for (int i = 2; i <= n; i++) {
			map[i] = map[i - 1] + map[i - 2];
		}

		return map[n];
	}
};