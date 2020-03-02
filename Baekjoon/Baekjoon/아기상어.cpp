#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct SharkInfo {
	int size;
	int eat;
	int y;
	int x;
	SharkInfo(int size, int eat, int y, int x) :size(size), eat(eat), y(y), x(x) {};
	SharkInfo() {};
};

struct FishInfo {
	int size;
	int dist;
	int y;
	int x;
	FishInfo(int size, int dist, int y, int x) :size(size), dist(dist), y(y), x(x) {};
	FishInfo() {};
};

SharkInfo shark;
vector<FishInfo> fishes;

int N;
int map[20][20];

bool compare(FishInfo A, FishInfo B) {
	if (A.size < shark.size && B.size < shark.size) {
		if (A.dist < B.dist) {
			return true;
		}
		else if (A.dist == B.dist) {
			if (A.y < B.y) {
				return true;
			}
			else if (A.y == B.y) {
				if (A.x < B.x) {
					return true;
				}
				return false;
			}
			return false;
		}
	}
	else {
		if (A.size < B.size) {
			return true;
		}
		return false;
	}
	
	return false;
}

void sortByDist() {
	//거리 계산
	for (int i = 0; i < fishes.size(); i++) {
		fishes[i].dist = abs(fishes[i].y - shark.y) + abs(fishes[i].x - shark.x);
	}
	sort(fishes.begin(), fishes.end(), compare);
}

int countSec() {

	int res = 0;

	while (1) {
		sortByDist();



	}

	

	return 0;
}

int main() {

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x]) {
				if (map[y][x] == 9)
					shark = SharkInfo(2, y, x, 0);
				else
					fishes.push_back(FishInfo(map[y][x], 0, y, x));
			}
		}
	}

	cout << countSec() << endl;

	return 0;
}