#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool brackets(const string& word) {
	if (word[0] == ')' || word[0] == '}' || word[0] == ']') return false;
	stack<char> st;

	for (int i = 0; i < word.size(); i++) {
		if (word[i] == '(' || word[i] == '{' || word[i] == '[') {
			st.push(word[i]);
		}
		else {
			if (st.size() == 0) return false;
			if (st.top() == '(' && word[i] == ')') st.pop();
			else if (st.top() == '{' && word[i] == '}') st.pop();
			else if (st.top() == '[' && word[i] == ']') st.pop();
			else return false;
		}
	}

	return st.size() == 0;
}

bool brackets2(const string& word) {
	const string opening("({["), closing(")}]");

	stack<char> st;

	for (int i = 0; i < word.size(); i++) {
		if (opening.find(word[i]) != -1) st.push(word[i]);
		else {
			if (st.empty()) return false;
			if (opening.find(st.top()) != closing.find(word[i])) return false;
			st.pop();
		}
	}

	return st.empty();
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		string word;
		cin >> word;

		//cout << (brackets(word) ? "YES" : "NO") << endl;
		cout << (brackets2(word) ? "YES" : "NO") << endl;
	}

	return 0;
}