#include<iostream>
#include<string>
#include<cstring>

using namespace std;

char map[5][5];
string words[10];
int cache[10][5][5];
int N;
//12시부터 시계방향으로
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int findWord(const string& word, int y, int x, int cnt) {
	if (y < 0 || y >= 5 || x < 0 || x >= 5) return 0;
	if (word.size() == 1) return word[0] == map[y][x];

	int& res = cache[cnt][y][x];
	if (res != -1) return res;

	if (word[0] != map[y][x]) return res = 0;
	
	for (int i = 0; i < 8; i++) {
		if (res = findWord(word.substr(1), y + dy[i], x + dx[i], cnt + 1)) return res;
	}

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> map[i][j];
			}
		}
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> words[i];
		}

		for (int i = 0; i < N; i++) {
			memset(cache, -1, sizeof(cache));
			int flag;
			for (int y = 0; y < 5; y++) {
				flag = 0;
				for (int x = 0; x < 5; x++) {
					if (flag = findWord(words[i], y, x, 0)) break;
				}
				if (flag) break;
			}
			cout << words[i] << " " << (flag ? "YES" : "NO") << endl;
		}

	}

	return 0;
}