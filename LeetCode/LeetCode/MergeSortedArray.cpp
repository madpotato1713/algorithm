class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = 0; i < n; i++) {
			nums1[i + m] = nums2[i];
		}

		quickSort(nums1, 0, n + m - 1);
	}

	void quickSort(vector<int>& nums, int l, int r) {
		if (l >= r) return;

		int pivot = nums[(l + r) / 2];
		int left = l;
		int right = r;

		while (left <= right) {
			while (pivot > nums[left])
				left++;
			while (pivot < nums[right])
				right--;
			if (left <= right) {
				swap(nums[left], nums[right]);
				left++;
				right--;
			}
		}
		quickSort(nums, l, right);
		quickSort(nums, left, r);
	}
};