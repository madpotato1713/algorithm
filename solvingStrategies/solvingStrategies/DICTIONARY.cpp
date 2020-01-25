#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

int adj[26][26];
int visited[26];
vector<int> order;

void setAdj(const vector<string>& words) {
	memset(adj, 0, sizeof(adj));

	for (int i = 0; i < words.size() - 1; i++) {
		int length = min(words[i].size(), words[i + 1].size());
		for (int j = 0; j < length; j++) {
			if (words[i][j] != words[i + 1][j]) {
				adj[words[i][j] - 'a'][words[i + 1][j] - 'a'] = 1;
				break;
			}
		}
	}
}

void dfs(int vertex) {
	visited[vertex] = 1;

	for (int i = 0; i < 26; i++) {
		if (adj[vertex][i] && !visited[i]) {
			dfs(i);
		}
	}

	order.push_back(vertex);
}

void dfsAll() {
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < 26; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	reverse(order.begin(), order.end());

	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			if (adj[order[j]][order[i]]) {
				cout << "INVALID HYPOTHESIS" << endl;
				return;
			}
		}
	}


	for (int i = 0; i < 26; i++) {
		cout << (char)(order[i] + 'a');
	}
	cout << endl;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		int N;
		cin >> N;
		vector<string> words(N);
		for (int i = 0; i < N; i++) {
			cin >> words[i];
		}

		setAdj(words); //DAG(Directed Acyclic Grapth) ¸¸µé±â
		dfsAll();
	}

	return 0;
}