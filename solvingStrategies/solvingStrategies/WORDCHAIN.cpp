#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int N;
vector<string> words;
vector<vector<int>> adj;
vector<int> visited;
vector<int> order;



int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> N;
		words = vector<string>(N);
		for (int i = 0; i < N; i++) {
			cin >> words[i];
		}

	}

	return 0;
}