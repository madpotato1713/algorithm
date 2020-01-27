// case 1
class Solution {
public:
	int mySqrt(int x) {
		return pow(x, 0.5);
	}
};


// case 2
class Solution {
public:
	int mySqrt(int x) {

		long left = 1;
		long right = x;

		while (left <= right)
		{
			long mid = (left + right) / 2;

			if (mid == x / mid)
				return mid;
			else if (mid < x / mid)
				left = mid + 1;
			else
				right = mid - 1;
		}

		return left - 1;
	}
};