class Solution {
public:
	int arr[31];

	int fib(int N) {
		if (N <= 1) return N;

		memset(arr, 0, sizeof(arr));
		arr[0] = 0; arr[1] = 1;

		for (int i = 2; i <= N; i++) {
			arr[i] = arr[i - 1] + arr[i - 2];
		}

		return arr[N];

	}
};