class Solution {
public:
	string addBinary(string a, string b) {
		if (a.size() < b.size()) {
			string tmp = a;
			a = b;
			b = tmp;
		}

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		for (int i = 0; i < b.size(); i++) {
			int na = a[i] - '0';
			int nb = b[i] - '0';

			if (na + nb > 1) {
				a[i] = ('0' + na + nb - 2);
				if (i == a.size() - 1) a += "1";
				else a[i + 1]++;
			}
			else {
				a[i] = ('0' + na + nb);
			}
		}

		for (int i = b.size(); i < a.size(); i++) {
			if (a[i] == '2') {
				a[i] = '0';
				if (i == a.size() - 1) a += "1";
				else a[i + 1]++;
			}
			else break;
		}

		reverse(a.begin(), a.end());
		return a;
	}
};

// �Է��� �ʹ�Ŀ�� �ȵ�
class Solution {
public:
	string addBinary(string a, string b) {
		long long sum = 0;
		string res;

		int idx = 0;
		for (int i = a.size() - 1; i >= 0; i--) {
			sum += pow(2, idx) * (a[i] - '0');
			idx++;
		}

		idx = 0;
		for (int i = b.size() - 1; i >= 0; i--) {
			sum += pow(2, idx) * (b[i] - '0');
			idx++;
		}

		if (sum == 0) return "0";

		while (sum > 0) {
			res += to_string(sum % 2);
			sum /= 2;
		}

		reverse(res.begin(), res.end());
		return res;
	}
};