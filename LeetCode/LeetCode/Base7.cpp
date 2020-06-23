class Solution {
public:
	string convertToBase7(int num) {
		if (!num)
			return "0";

		string res = "";
		int n = abs(num);


		while (n > 0) {
			res += to_string(n % 7);
			n /= 7;
		}

		if (num < 0)
			res += "-";

		reverse(res.begin(), res.end());

		return res;
	}
};