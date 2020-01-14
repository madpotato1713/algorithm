#include<iostream>


using namespace std;

char map[3][3];


int canWin() {

}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				cin >> map[y][x];
			}
		}


	}

	return 0;
}