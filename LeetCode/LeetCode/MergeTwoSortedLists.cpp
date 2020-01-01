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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		ListNode* head = new ListNode(0);
		ListNode* pt = head;

		while (l1 != NULL && l2 != NULL) {
			if (l1->val <= l2->val) {
				pt->next = l1;
				l1 = l1->next;
			}
			else {
				pt->next = l2;
				l2 = l2->next;
			}
			pt = pt->next;
		}

		if (l1 != NULL) {
			pt->next = l1;
		}
		else if (l2 != NULL) {
			pt->next = l2;
		}

		return head->next;
	}
};