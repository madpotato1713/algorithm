#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int N, W;	//가져가고 싶은 물건의 수(<=100), 캐리어의 용량(<=1000)
string names[100];
int volume[100];
int desperate[100];

int dSum = 0;

int packing(int vSum, int idx) {

}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> N >> W;
		for (int i = 0; i < N; i++) {
			cin >> names[i] >> volume[i] >> desperate[i];
		}

		
	}

	return 0;
}