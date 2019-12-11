#include<iostream>
#include<string>
#include<vector>

using namespace std;

int m, q;	//단어의 수<=500, 처리 문장 수<=100
vector<string> dict;
vector<float> first;
float T[500][500];
float M[500][500];
vector<vector<string>> words;

void init() {
	dict.resize(m);
	first.resize(m);
	words.resize(q);
}



int main() {

	//빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> q;

	init();

	for (int i = 0; i < m; i++) {
		cin >> dict[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> first[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> T[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];
		}
	}
	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;
		words[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> words[i][j];
		}
	}





	return 0;
}