/* CASE1 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		vector<int> nums;
		while (head) {
			nums.push_back(head->val);
			head = head->next;
		}

		for (int i = 0; i < nums.size() / 2; i++) {
			if (nums[i] != nums[nums.size() - 1 - i])
				return false;
		}

		return true;
	}
};

/* CASE2 */
class Solution {
public:
	ListNode* temp;
	bool isPalindrome(ListNode* head) {
		temp = head;
		return check(head);
	}

	bool check(ListNode* p) {
		if (NULL == p) return true;
		bool isPal = check(p->next) & (temp->val == p->val);
		temp = temp->next;
		return isPal;
	}
};