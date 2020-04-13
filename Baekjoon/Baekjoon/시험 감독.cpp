#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N, A, B, C;
vector<int> nums;

int main() {

	int res = 0;

	cin >> N;
	nums = vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	cin >> B >> C;
	
	for (int i = 0; i < N; i++) {
		nums[i] = (nums[i] - B >= 0 ? nums[i] - B : 0);
	}
	res += N;

	for (int i = 0; i < N; i++) {
		double div = ceil((double)nums[i] / C);
		res += div;
	}

	cout << res << endl;

	return 0;
}