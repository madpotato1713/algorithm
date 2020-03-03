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
	ListNode* removeElements(ListNode* head, int val) {
		while (head) {
			if (head->val == val) {
				head = head->next;
			}
			else {
				break;
			}
		}

		ListNode* pt = head;

		while (head) {
			if (head->next == NULL) break;
			if (head->next->val == val) {
				head->next = head->next->next;
			}
			else {
				head = head->next;
			}
		}

		return pt;
	}
};