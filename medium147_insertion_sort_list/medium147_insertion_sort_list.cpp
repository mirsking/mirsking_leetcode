#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL)
			return NULL;

		ListNode* p;
		ListNode* q = head->next;
		ListNode* q_par = head;
		ListNode* head_par = new ListNode(-100);
		ListNode* p_par = head_par;
		while (q != NULL)
		{
			p = head;
			p_par = head_par;
			while (p != q)
			{
				if (p->val > q->val)
				{
					q_par->next = q->next;
					q->next = p;
					p = q;

					if (p->next == head)
						head = p;
					else
						p_par->next = p;

					q = q_par;
					break;
				}
				p_par = p;
				p = p->next;
			}
			q_par = q;
			q = q->next;
		}

		return head;
    }
};

int main()
{
	ListNode a(3), b(4), c(1), e(2), d(0);
	a.next = &b;
	b.next = &c;
	c.next = &e;
	e.next = &d;
	Solution sol;
	ListNode* res = sol.insertionSortList(&a);
	return 0;
}