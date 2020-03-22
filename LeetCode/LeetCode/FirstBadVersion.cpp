// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {

		long start = 0;
		long end = n;

		while (end > 1) {
			long mid = (start + end) / 2;

			//둘다 false
			if (!isBadVersion(mid) && !isBadVersion(mid + 1)) {
				start = mid;
			}
			//둘다 true
			else if (isBadVersion(mid) && isBadVersion(mid + 1)) {
				end = mid;
			}
			else {
				return mid + 1;
			}
		}

		return end;
	}
};