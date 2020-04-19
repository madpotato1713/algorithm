/* CASE1 */
class Solution {
public:
	string addStrings(string num1, string num2) {
		int len = max(num1.size(), num2.size());
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		string res = "";
		vector<int> sum(len + 1, 0);

		for (int i = 0; i < len; i++) {
			int n1 = i < num1.size() ? (num1[i] - '0') : 0;
			int n2 = i < num2.size() ? (num2[i] - '0') : 0;
			sum[i] = (n1 + n2);
		}
		for (int i = 0; i < len; i++) {
			if (sum[i] >= 10) {
				sum[i + 1] += (sum[i] / 10);
				sum[i] %= 10;
			}
		}

		for (int i = 0; i < len; i++) {
			res += (sum[i] + '0');
		}
		if (sum[len] > 0) {
			res += (sum[len] + '0');
		}

		reverse(res.begin(), res.end());
		return res;
	}
};

/* CASE2 */
class Solution {
public:
	string addStrings(string num1, string num2) {
		int len = max(num1.size(), num2.size());
		int len1 = num1.size();
		int len2 = num2.size();

		string res = "";
		vector<int> sum(len + 1, 0);

		for (int s = len, i = len1 - 1, j = len2 - 1; s > 0; s--, i--, j--) {
			int n1 = i >= 0 ? (num1[i] - '0') : 0;
			int n2 = j >= 0 ? (num2[j] - '0') : 0;
			sum[s] = (n1 + n2);
		}

		for (int s = len; s > 0; s--) {
			if (sum[s] >= 10) {
				sum[s - 1] += (sum[s] / 10);
				sum[s] %= 10;
			}
		}

		for (int s = len; s > 0; s--) {
			res += (sum[s] + '0');
		}
		if (sum[0] > 0) {
			res += (sum[0] + '0');
		}

		reverse(res.begin(), res.end());

		return res;
	}
};

/* CASE3 */
class Solution {
public:
	string addStrings(string num1, string num2) {
		int len = max(num1.size(), num2.size());
		int len1 = num1.size();
		int len2 = num2.size();

		string res = "";
		vector<int> sum(len + 1, 0);

		for (int s = len, i = len1 - 1, j = len2 - 1; s > 0; s--, i--, j--) {
			int n1 = i >= 0 ? (num1[i] - '0') : 0;
			int n2 = j >= 0 ? (num2[j] - '0') : 0;
			sum[s] = (n1 + n2);
			res += " ";
		}

		for (int s = len; s > 0; s--) {
			if (sum[s] >= 10) {
				sum[s - 1] += (sum[s] / 10);
				sum[s] %= 10;
			}
		}

		for (int s = len - 1; s >= 0; s--) {
			res[s] = (sum[s + 1] + '0');
		}
		if (sum[0] > 0) {
			string str = "";
			str += (sum[0] + '0');
			res = (str + res);
		}

		return res;
	}
};