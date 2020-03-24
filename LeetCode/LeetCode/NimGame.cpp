/* CASE1 */
class Solution {
public:
	bool canWinNim(int n) {

		return solve(0, n); //0: 내턴, 1: 상대방턴
	}

	bool solve(int turn, int n) {
		if (turn == 1 && n <= 3) {
			return false;
		}
		if (turn == 0 && n <= 3) {
			return true;
		}

		int res = turn;
		for (int i = 1; i <= 3; i++) {
			if (turn == 0) {
				res |= solve(1, n - i);
			}
			else {
				res &= solve(0, n - i);
			}
		}

		return res;
	}
};

/* CASE2 */
class Solution {
public:
	bool canWinNim(int n) {
		return (n % 4);
	}
};