#include<iostream>
#include<string>

using namespace std;

void quadTree(const string& word) {
	if (word.size() == 1) {
		cout << word;
		return;
	}

	int idx[4] = { 0 };
	int count = 1;
	int cnt = 0;
	int idxCnt = 0;
	for (int i = 1; i < word.size(); i++) {
		cnt++;
		if (count == cnt) {
			idx[idxCnt] = i;
			idxCnt++;
			count = 1;
			cnt = 0;
		}

		if (word[i] == 'x') count += 4;

	}

	cout << "x";
	quadTree(word.substr(idx[2], idx[3] - idx[2]));
	quadTree(word.substr(idx[3]));
	quadTree(word.substr(idx[0], idx[1] - idx[0]));
	quadTree(word.substr(idx[1], idx[2] - idx[1]));
}

string quadTree2(string::iterator& itr) {
	char head = *itr;
	itr++;

	if (head == 'w' || head == 'b') {
		return string(1, head);
	}

	string upperLeft = quadTree2(itr);
	string upperRight = quadTree2(itr);
	string lowerLeft = quadTree2(itr);
	string lowerRight = quadTree2(itr);

	return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		string word;
		cin >> word;

		string::iterator itr = word.begin();
		cout << quadTree2(itr) << endl;
		//quadTree(word);
		//cout << endl;
	}

	return 0;
}