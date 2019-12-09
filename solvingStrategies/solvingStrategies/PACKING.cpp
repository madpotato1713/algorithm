#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int N, W;	//물건 개수, 캐리어 용량
vector<string> names;
vector<int> weight;
vector<int> desperate;
int cache[1000][100];
vector<int> saved;

void init() {
	names.resize(N);
	weight.resize(N);
	desperate.resize(N);
	memset(cache, -1, sizeof(cache));
	saved.clear();
}

int packing(int capa, int idx) {
	if (idx == N) return 0;

	int& res = cache[capa][idx];
	if (res != -1) return res;

	res = packing(capa, idx + 1);

	if (capa >= weight[idx]) {
		res = max(res, packing(capa - weight[idx], idx + 1) + desperate[idx]);
	}

	return res;
}

void tracking(int capa, int idx) {
	if (idx == N) return;

	if (packing(capa, idx) == packing(capa, idx + 1)) {
		tracking(capa, idx + 1);
	}
	else {
		saved.push_back(idx);
		tracking(capa - weight[idx], idx + 1);
	}
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> N >> W;

		init();

		for (int i = 0; i < N; i++) {
			cin >> names[i] >> weight[i] >> desperate[i];
		}

		cout << packing(W, 0) << " ";
		tracking(W, 0);
		cout << saved.size() << endl;

		for (int i = 0; i < saved.size(); i++) {
			cout << names[saved[i]] << endl;
		}
	}

	return 0;
}