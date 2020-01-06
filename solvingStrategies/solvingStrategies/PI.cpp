#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

//const int& INF = numeric_limits<int>::max();
const int& INF = 987654321;
int cache[10000];
string nums;

int difficulty(int start, int end) {

	int res = 10;
	bool check;

	//난이도 1 : 모든 숫자가 같을 때
	check = true;
	for (int i = start; i < end; i++) {
		if (nums[i] != nums[i + 1]) {
			check = false;
			break;
		}
	}
	if (check) return 1;

	//난이도 2 : 숫자가 1씩 단조 증가하거나 단조 감소할 때
	check = true;
	for (int i = start; i < end - 1; i++) {
		int prev = nums[i] - nums[i + 1], next = nums[i + 1] - nums[i + 2];
		if (abs(prev) != 1 || prev != next) {
			check = false;
			break;
		}
	}
	if (check) return 2;

	//난이도 4 : 두 개의 숫자가 번갈아가며 나타날 때
	check = true;
	for (int i = start; i < end - 1; i++) {
		if (nums[i] != nums[i + 2]) {
			check = false;
			break;
		}
	}
	if (check) return 4;

	//난이도 5 : 이 숫자가 등차 수열을 이룰 때
	check = true;
	for (int i = start; i < end - 1; i++) {
		if ((nums[i] - nums[i + 1]) != (nums[i + 1] - nums[i + 2])) {
			check = false;
			break;
		}
	}
	if (check) return 5;

	return res;
}

int easist(int idx) {
	int size = nums.size();
	if (idx == size) return 0;
	if (idx + 2 >= size) return INF;

	int& res = cache[idx];
	if (res != -1) return res;

	res = INF;
	for (int i = 2; i <= 4; i++) {
		//res = min(res, difficulty(idx, idx + i) + easist(idx + i + 1) >= 0 ? difficulty(idx, idx + i) + easist(idx + i + 1) : INF);
		res = min(res, difficulty(idx, idx + i) + easist(idx + i + 1));
	}

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		memset(cache, -1, sizeof(cache));
		cin >> nums;

		cout << easist(0) << endl;
	}

	return 0;
}