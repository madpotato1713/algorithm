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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) return head;

		ListNode* pt = head;

		int val = pt->val;

		while (pt->next != NULL) {
			if (val == pt->next->val) {
				if (pt->next->next == NULL) {
					pt->next = NULL;
					break;
				}
				pt->next = pt->next->next;
			}
			else {
				pt = pt->next;
				val = pt->val;
			}

		}


		return head;
	}
};