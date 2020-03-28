/* CASE1 */
class NumArray {
	vector<int> v;

public:
	NumArray(vector<int>& nums) {
		v = nums;
	}

	int sumRange(int i, int j) {

		int sum = 0;
		for (; i <= j; i++) {
			sum += v[i];
		}

		return sum;
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

/* CASE2 */
class NumArray {
private:
	vector<int> v;

public:
	NumArray(vector<int>& nums) {
		int acc = 0;

		for (auto n : nums) {
			acc += n;
			v.push_back(acc);
		}
	}

	int sumRange(int i, int j) {
		if (i == 0)
			return v[j];

		return v[j] - v[i - 1];
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */