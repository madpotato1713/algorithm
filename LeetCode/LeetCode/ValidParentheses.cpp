class Solution {
public:
	bool isValid(string s) {
		if (s.size() % 2 != 0) return false;

		stack<char> st;

		for (int i = 0; i < s.size(); i++) {
			char ch = s[i];
			if (ch == '(' || ch == '[' || ch == '{') {
				st.push(ch);
			}
			else {
				if (st.empty()) return false;

				char top = st.top();
				if ((top == '(' && ch == ')')
					|| (top == '[' && ch == ']')
					|| (top == '{' && ch == '}')) {
					st.pop();
				}
				else return false;
			}
		}


		return st.empty();
	}
};