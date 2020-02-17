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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_map<ListNode*, int> um;
		while (headA != NULL) {
			um[headA]++;
			headA = headA->next;
		}

		while (headB != NULL) {
			if (um[headB]) {
				return headB;
			}
			headB = headB->next;
		}

		return NULL;
	}
};

/* CASE2 */
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

		while (headA != NULL) {
			ListNode* b = headB;

			while (b != NULL) {
				if (headA == b)
					return headA;
				b = b->next;
			}

			headA = headA->next;
		}

		return NULL;
	}
};

/* CASE3 */
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
	int length(ListNode *node) {
		int len = 0;
		while (node) {
			len++;
			node = node->next;
		}
		return len;
	}

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* ha = headA;
		ListNode* hb = headB;

		int len = length(headA) - length(headB);

		while (len > 0) {
			len--;
			ha = ha->next;
		}
		while (len < 0) {
			len++;
			hb = hb->next;
		}

		while (ha && hb) {
			if (ha == hb) {
				return ha;
			}
			ha = ha->next;
			hb = hb->next;
		}

		return NULL;
	}
};