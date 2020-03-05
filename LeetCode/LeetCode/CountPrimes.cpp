class Solution {
public:
	int countPrimes(int n) {
		int res = 0;
		if (n >= 3)
			res++;

		for (int i = 3; i < n; i += 2) {
			if (isPrime(i))
				res++;
		}

		return res;
	}

	bool isPrime(int n) {
		for (int i = 3; i <= sqrt(n); i += 2) {
			if (n % i == 0)
				return false;
		}

		return true;
	}
};

