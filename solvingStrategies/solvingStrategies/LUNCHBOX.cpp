#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> heatTime, eatingTime;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first > p2.first) return true;
	else if (p1.first == p2.first && p2.second > p2.second) return true;
	return false;
}

int getTime() {
	vector<pair<int, int>> time(n);
	for (int i = 0; i < n; i++) {
		time[i] = make_pair(eatingTime[i], heatTime[i]);
	}

	//sort(time.begin(), time.end(), greater<pair<int, int>>());
	sort(time.begin(), time.end(), compare);

	int res = 0;	//첫 번째 도시락을 데우는 시간
	int restEat = 0;
	for (int i = 0; i < n; i++) {
		res += time[i].second;	//도시락 데우는 시간 더해줌
		//데우고 나면 먹음
		restEat = max(restEat - time[i].second, time[i].first);
	}

	return res + restEat;
}

int getTime2() {
	vector<pair<int, int>> order;
	for (int i = 0; i < n; i++) {
		order.push_back(make_pair(-eatingTime[i], i));
	}

	sort(order.begin(), order.end());
	
	int ret = 0, beginEat = 0;
	for (int i = 0; i < n; i++) {
		int box = order[i].second;
		beginEat += heatTime[box];
		ret = max(ret, beginEat + eatingTime[box]);
	}

	return ret;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> n;
		heatTime = eatingTime = vector<int>(n);

		for (int i = 0; i < n; i++) {
			cin >> heatTime[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> eatingTime[i];
		}

		//cout << getTime() << endl;
		cout << getTime2() << endl;
	}

	return 0;
}