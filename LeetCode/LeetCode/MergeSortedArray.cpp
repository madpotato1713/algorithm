//buble sort
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = 0; i < n; i++) {
			nums1[i + m] = nums2[i];
		}

		for (int i = 0; i < m + n; i++) {
			for (int j = 0; j < m + n - i - 1; j++) {
				if (nums1[j] > nums1[j + 1]) {
					int tmp = nums1[j];
					nums1[j] = nums1[j + 1];
					nums1[j + 1] = tmp;
				}
			}
		}
	}
};


//quick sort
class Solution {
public:
	void quickSort(vector<int>& nums, int i, int j) {
		if (i >= j) return;

		int pivot = nums[(i + j) / 2];
		int left = i;
		int right = j;

		while (left <= right) {
			while (nums[left] < pivot) left++;
			while (nums[right] > pivot) right--;
			if (left <= right) {
				swap(nums[left], nums[right]);
				left++;
				right--;
			}
		}
		quickSort(nums, i, right);
		quickSort(nums, left, j);
	}

	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = 0; i < n; i++) {
			nums1[i + m] = nums2[i];
		}

		quickSort(nums1, 0, n + m - 1);
	}
};