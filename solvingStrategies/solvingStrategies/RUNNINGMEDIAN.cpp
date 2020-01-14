#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct RNG {
	int seed, a, b;
	RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
	int next() {
		int ret = seed;
		seed = ((seed * (long long)a) + b) % 20090711;
		return ret;
	}
};

int medianSum(vector<long long>& seq) {
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int sum = 0;

	for (int i = 0; i < seq.size(); i++) {
		//maxHeap과 minHeap을 번갈어 넣는다.
		if (i % 2 == 0) maxHeap.push(seq[i]);
		else if (i % 2 == 1) minHeap.push(seq[i]);

		if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
			int maxTop = maxHeap.top(); maxHeap.pop();
			int minTop = minHeap.top(); minHeap.pop();

			maxHeap.push(minTop);
			minHeap.push(maxTop);
		}

		sum += maxHeap.top();
		sum %= 20090711;
	}

	return sum;
}

int medianSum2(int n, RNG rng) {
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	int sum = 0;

	for (int i = 0; i < n; i++) {
		//maxHeap과 minHeap을 번갈어 넣는다.
		if (i % 2 == 0) maxHeap.push(rng.next());
		else if (i % 2 == 1) minHeap.push(rng.next());

		if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
			int maxTop = maxHeap.top(); maxHeap.pop();
			int minTop = minHeap.top(); minHeap.pop();

			maxHeap.push(minTop);
			minHeap.push(maxTop);
		}

		sum += maxHeap.top();
		sum %= 20090711;
	}

	return sum;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		int N, a, b;
		cin >> N >> a >> b;

		/*vector<long long> seq(N);
		seq[0] = 1983;
		for (int i = 1; i < N; i++) {
			seq[i] = (seq[i - 1] * a + b) % 20090711;
		}*/

		//cout << medianSum(seq) << endl;
		cout << medianSum2(N, RNG(a, b)) << endl;
	}
	
	return 0;
}