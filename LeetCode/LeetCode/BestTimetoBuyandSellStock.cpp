#include<iostream>
#include<vector>

using namespace std;

int main() {

	return 0;
}

///* CASE1 */
//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		int size = prices.size();
//		int res = 0;
//
//		for (int i = 0; i < size - 1; i++) {
//			for (int j = i + 1; j < size; j++) {
//				res = max(res, prices[j] - prices[i]);
//			}
//		}
//
//		return res;
//	}
//};
//
//
