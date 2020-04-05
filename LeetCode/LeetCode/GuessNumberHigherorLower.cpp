/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
	int guessNumber(int n) {
		if (guess(n) == 0)
			return n;

		long start = 1, end = n;
		long res = (start + end) / 2;

		while (start < end) {
			res = (start + end) / 2;

			int dec = guess(res);
			if (dec == 0) {
				break;
			}
			else if (dec == 1) {
				start = res;
			}
			else {
				end = res;
			}
		}

		return res;
	}
};