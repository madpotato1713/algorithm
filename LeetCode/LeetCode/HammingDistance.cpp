class Solution {
public:
	int hammingDistance(int x, int y) {

		if (x < y) {
			int temp = x;
			x = y;
			y = temp;
		}

		string sx = "", sy = "";

		while (x > 0) {
			sx += ((x % 2) + '0');
			x /= 2;
		}

		while (y > 0) {
			sy += ((y % 2) + '0');
			y /= 2;
		}

		int res = 0;
		for (int i = 0; i < sx.size(); i++) {
			if (i < sy.size()) {
				if (sx[i] != sy[i])
					res++;
			}
			else {
				if (sx[i] == '1')
					res++;
			}
		}

		return res;
	}
};