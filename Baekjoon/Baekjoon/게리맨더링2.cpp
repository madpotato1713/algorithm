#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 987654321;
int N;
int map[21][21];

int diff(int x, int y, int d1, int d2) {
	//경계선
	//(x, y), (x + 1, y - 1), ..., (x + d1, y - d1)
	//(x, y), (x + 1, y + 1), ..., (x + d2, y + d2)
	//(x + d1, y - d1), (x + d1 + 1, y - d1 + 1), ... (x + d1 + d2, y - d1 + d2)
	//(x + d2, y + d2), (x + d2 + 1, y + d2 - 1), ..., (x + d2 + d1, y + d2 - d1)
	//선거구
	//1번 선거구 : 1 ≤ r < x + d1, 1 ≤ c ≤ y
	//2번 선거구 : 1 ≤ r ≤ x + d2, y < c ≤ N
	//3번 선거구 : x + d1 ≤ r ≤ N, 1 ≤ c < y - d1 + d2
	//4번 선거구 : x + d2 < r ≤ N, y - d1 + d2 ≤ c ≤ N
	vector<int> population(5, 0);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			//1번 선거구
			if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x))) {
				population[0] += map[r][c];
			}
			//2번 선거구
			else if (r <= x + d2 && c > y && !(r >= x && c <= y + (r - x))) {
				population[1] += map[r][c];
			}
			//3번 선거구
			else if (r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r)))) {
				population[2] += map[r][c];
			}
			//4번 선거구
			else if (r > x + d2 && c >= y - d1 + d2 && !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r)))) {
				population[3] += map[r][c];
			}
			//5번 선거구
			else {
				population[4] += map[r][c];
			}
		}
	}

	sort(population.begin(), population.end());

	return population[4] - population[0];
}

int minDiff() {
	int res = INF;

	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; d1 <= y - 1 && d1 <= N - x - 1; d1++) {
				for (int d2 = 1; d2 <= N - y && d2 <= N - x - 1; d2++) {
					res = min(res, diff(x, y, d1, d2));
				}
			}
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> map[x][y];
		}
	}

	cout << minDiff() << endl;

	return 0;
}

/* CASE1 */
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<cstring>
//
//using namespace std;
//
//const int INF = 987654321;
//int N;	//map의 길이
//int map[21][21];
//int dist[21][21];
//
//int calcDiff(int x, int y, int d1, int d2) {
//	
//	//1번 선거구 : 1 ≤ r < x + d1, 1 ≤ c ≤ y
//	//2번 선거구 : 1 ≤ r ≤ x + d2, y < c ≤ N
//	//3번 선거구 : x + d1 ≤ r ≤ N, 1 ≤ c < y - d1 + d2
//	//4번 선거구 : x + d2 < r ≤ N, y - d1 + d2 ≤ c ≤ N
//	vector<int> person(5, 0);
//
//	for (int r = 1; r <= N; r++) {
//		for (int c = 1; c <= N; c++) {
//			//5번 선거구에 들어가는 조건
//			if (dist[r][c] == 5) {
//				person[4] += map[r][c];
//			}
//			else if (1 <= r && r < x + d1 && 1 <= c && c <= y) {
//				dist[r][c] = 1;
//				person[0] += map[r][c];
//			}
//			else if (1 <= r && r <= x + d2 && y < c && y <= N) {
//				dist[r][c] = 2;
//				person[1] += map[r][c];
//			}
//			else if (x + d1 <= r && r <= N && 1 <= c && c < y - d1 + d2) {
//				dist[r][c] = 3;
//				person[2] += map[r][c];
//			}
//			else if (x + d2 <= r && r <= N && y - d1 + d2 <= c && c <= N) {
//				dist[r][c] = 4;
//				person[3] += map[r][c];
//			}
//		}
//	}
//
//	sort(person.begin(), person.end());
//
//	return person[4] - person[0];
//}
//
//void setDist(int x, int y, int d1, int d2) {
//	//경계선
//	//(x, y), (x + 1, y - 1), ..., (x + d1, y - d1)
//	//(x, y), (x + 1, y + 1), ..., (x + d2, y + d2)
//	//(x + d1, y - d1), (x + d1 + 1, y - d1 + 1), ... (x + d1 + d2, y - d1 + d2)
//	//(x + d2, y + d2), (x + d2 + 1, y + d2 - 1), ..., (x + d2 + d1, y + d2 - d1)
//	for (int r = x, c = y; r <= x + d1; r++, c--) {
//		dist[r][c] = 5;
//	}
//	for (int r = x, c = y; r <= x + d2; r++, c++) {
//		dist[r][c] = 5;
//	}
//	for (int r = x + d1, c = y - d1; r <= x + d1 + d2; r++, c++) {
//		dist[r][c] = 5;
//	}
//	for (int r = x + d2, c = y + d2; r <= x + d2 + d1; r++, c--) {
//		dist[r][c] = 5;
//	}
//
//	for (int r = x + 1; r < x + d1 + d2; r++) {
//		int flag = -1;
//		for (int c = 1; c <= N; c++) {
//			if (flag == -1) {
//				if (dist[r][c] == 5)
//					flag = 0;
//			}
//			else if (!flag) {
//				if (dist[r][c] == 5)
//					break;
//				dist[r][c] = 5;
//			}
//		}
//	}
//}
//
//int minDiff() {
//	int res = INF;
//
//	//(d1, d2 ≥ 1, 1 ≤ x < x + d1 + d2 ≤ N, 1 ≤ y - d1 < y < y + d2 ≤ N)
//
//	for (int x = 1; x <= (N - 2); x++) {
//		for (int y = 2; y <= (N - 1); y++) {
//			for (int d1 = 1; (d1 < y) && (d1 < N); d1++) {
//				for (int d2 = 1; (d2 <= N - y) && (d2 <= N - x - d1); d2++) {
//					memset(dist, 0, sizeof(dist));
//					setDist(x, y, d1, d2);
//					res = min(res, calcDiff(x, y, d1, d2));
//				}
//			}
//		}
//	}
//
//	return res;
//}
//
//int main() {
//
//	cin >> N;
//	for (int x = 1; x <= N; x++) {
//		for (int y = 1; y <= N; y++) {
//			cin >> map[x][y];
//		}
//	}
//
//	cout << minDiff() << endl;
//
//	return 0;
//}