#include<iostream>
#include<vector>

using namespace std;

int N;	//보드의 크기
int K;	//사과의 개수
int L;	//뱀의 변환 정보
struct apple {
	int y;
	int x;
	apple() {};
	apple(int y, int x) :y(y), x(x) {};
};
vector<apple> apples;

//벽 또는 자기자신과 부딪히면 끝
int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		apples.push_back(apple(y, x));
	}
	cin >> L;


	return 0;
}