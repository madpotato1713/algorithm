///* CASE1 */
//class Solution {
//public:
//	vector<int> findDisappearedNumbers(vector<int>& nums) {
//		unordered_set<int> us;
//		vector<int> v;
//
//		for (auto n : nums) {
//			us.insert(n);
//		}
//
//		for (int i = 1; i <= nums.size(); i++) {
//			if (us.find(i) == us.end()) {
//				v.push_back(i);
//			}
//		}
//
//		return v;
//	}
//};

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> nums = { 4,3,2,7,8,2,3,1 };

	for (int num : nums) 
		while (nums[num - 1] != num) 
			swap(num, nums[num - 1]);

	return 0;
}