#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int N;
vector<string> words;
int adj[26][26];
int outEdge[26], inEdge[26];
vector<string> wordsMap[26][26];
vector<int> order;

void init();
void makeAdj();
int isEuler();
void getEulerCircuitOrTrail(int);
void getEuler(int);
void dfsAll();

int main() {
	
	int testCase;
	cin >> testCase;
	for (int tc = 0; tc < testCase; tc++) {
		cin >> N;

		init();
		for (int i = 0; i < N; i++) {
			cin >> words[i];
		}

		dfsAll();
	}

	return 0;
}

void init() {
	words = vector<string>(N);
	memset(adj, 0, sizeof(adj));
	memset(outEdge, 0, sizeof(outEdge));
	memset(inEdge, 0, sizeof(inEdge));
	for (int y = 0; y < 26; y++) {
		for (int x = 0; x < 26; x++) {
			wordsMap[y][x].clear();
		}
	}
	order.clear();
}

void makeAdj() {
	for (int i = 0; i < words.size(); i++) {
		int start = words[i][0] - 'a';
		int end = words[i][words[i].size() - 1] - 'a';
		//adj
		adj[start][end]++;
		//in.out
		outEdge[start]++;
		inEdge[end]++;
		//word
		wordsMap[start][end].push_back(words[i]);
	}
}

int isEuler() {
	//차이나는 정점은 둘 다 존재하거나 없음
	//차이나는 정점은 처음과 끝 두개만 존재
	//두 개의 차는 1
	int diffOut = 0, diffIn = 0;

	for (int i = 0; i < 26; i++) {
		int diff = outEdge[i] - inEdge[i];
		if (diff < -1 && diff > 1)
			return 0;
		if (diff == 1) diffOut++;
		if (diff == 1) diffIn++;
	}

	//Euler Circuit이면 1, trail이면 2를 리턴
	if (diffOut == 0 && diffIn == 0)
		return 1;
	else if (diffOut == 1 && diffIn == 1)
		return 2;

	return 0;
}

void getEuler(int here) {
	for (int next = 0; next < 26; next++) {
		while (adj[here][next] > 0) {
			adj[here][next]--;
			getEuler(next);
		}
	}

	order.push_back(here);
}

void getEulerCircuitOrTrail(int type) {
	//Euler Circuit인 경우
	if (type == 1) {
		for (int i = 0; i < 26; i++) {
			if (outEdge[i] > 0) {
				getEuler(i);
				return;
			}
		}
	}
	//Euler Trail인 경우
	else {
		for (int i = 0; i < 26; i++) {
			if (outEdge[i] - inEdge[i] == 1) {
				getEuler(i);
				return;
			}
		}
	}
}

void dfsAll() {
	makeAdj();

	int type = isEuler();
	if (!type) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	getEulerCircuitOrTrail(type);

	//모든 정점을 방문하지 않았다면 false;
	//정점간 단어가 1개이므로, order 개수가 단어 개수보다 1 많다.
	if (order.size() != words.size() + 1) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	//Euler circuit이면 reverse 할 필요 없으나, trail이면 해야 함
	reverse(order.begin(), order.end());

	for (int i = 0; i < order.size() - 1; i++) {
		cout << wordsMap[order[i]][order[i + 1]].back() << " ";
		wordsMap[order[i]][order[i + 1]].pop_back();
	}
	cout << endl;
}