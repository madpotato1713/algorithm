class Solution {
public:
	char nums[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

	string toHex(int num) {
		if (num == 0)
			return "0";

		string res = "";
		int flag = num >= 0 ? 1 : -1;
		if (flag == -1) {
			num += 1;
			num *= -1;
		}

		while (num > 0) {
			res += (nums[num % 16]);
			num /= 16;
		}

		if (flag == -1) {
			for (int i = res.size(); i < 8; i++) {
				res += " ";
			}
			for (int i = 0; i < 8; i++) {
				if (res[i] == ' ') {
					res[i] = 'f';
				}
				else if (res[i] >= '0' && res[i] <= '9') {
					res[i] = nums[15 - (res[i] - '0')];
				}
				else {
					res[i] = nums[15 - (res[i] - 'a' + 10)];
				}
			}
		}

		reverse(res.begin(), res.end());
		return res;
	}
};