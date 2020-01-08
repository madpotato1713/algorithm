#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void postorder(const vector<int>& preorder, const vector<int>& inorder, const int& N) {

	//기저: N = 0일 때
	if (N == 0) return;
	//기저: N = 1일 때
	if (N == 1) {
		cout << preorder[0] << " ";
		return;
	}

	int idx;
	for (int i = 0; i < N; i++) {
		if (inorder[i] == preorder[0]) {
			idx = i;
			break;
		}
	}

	//left
	postorder(vector<int>(preorder.begin() + 1, preorder.begin() + 1 + idx)
		, vector<int>(inorder.begin(), inorder.begin() + idx), idx);

	//right
	postorder(vector<int>(preorder.begin() + 1 + idx, preorder.end())
		, vector<int>(inorder.begin() + idx + 1, inorder.end()), N - idx - 1);

	//parent
	cout << preorder[0] << " ";
}

void postorder2(const vector<int>& preorder, const vector<int>& inorder) {

	//기저: 빈 벡터일 때
	if (preorder.empty()) return;

	int N = preorder.size();
	int idx = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

	//left
	postorder2(vector<int>(preorder.begin() + 1, preorder.begin() + 1 + idx)
		, vector<int>(inorder.begin(), inorder.begin() + idx));

	//right
	postorder2(vector<int>(preorder.begin() + 1 + idx, preorder.end())
		, vector<int>(inorder.begin() + idx + 1, inorder.end()));

	//parent
	cout << preorder[0] << " ";
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		int N;
		cin >> N;

		vector<int> preorder(N, 0), inorder(N, 0);

		for (int i = 0; i < N; i++) {
			cin >> preorder[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> inorder[i];
		}

		postorder2(preorder, inorder);
		cout << endl;
	}

	return 0;
}