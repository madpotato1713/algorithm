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
	ListNode* reverseList(ListNode* head) {
		if (!head)
			return head;

		vector<int> v;
		ListNode* res;
		ListNode* pt;

		while (head) {
			v.push_back(head->val);
			head = head->next;
		}

		pt = new ListNode(v[v.size() - 1]);
		res = pt;
		for (int i = v.size() - 2; i >= 0; i--) {
			pt->next = new ListNode(v[i]);
			pt = pt->next;
		}

		return res;
	}
};