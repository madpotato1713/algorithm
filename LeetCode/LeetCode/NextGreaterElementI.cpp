/* CASE1 */
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;

		for (int i = 0; i < nums1.size(); i++) {
			res.push_back(-1);

			bool flag = false;
			for (int j = 0; j < nums2.size(); j++) {
				if (nums1[i] == nums2[j]) {
					flag = true;
				}
				if (flag && nums1[i] < nums2[j]) {
					res[i] = nums2[j];
					break;
				}
			}
		}

		return res;
	}
};

/* CASE2 */
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		unordered_map<int, int> um;
		for (int i = 0; i < nums2.size(); i++) {
			um[nums2[i]] = i;
		}

		for (int i = 0; i < nums1.size(); i++) {
			int r = -1;
			for (int j = um[nums1[i]]; j < nums2.size(); j++) {
				if (nums1[i] < nums2[j]) {
					r = nums2[j];
					break;
				}
			}
			res.push_back(r);
		}

		return res;
	}
};