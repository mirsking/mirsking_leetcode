#include <iostream>
#include <vector>
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
    ListNode* partition(ListNode* head, int x) {
		ListNode *less(NULL), *greater(NULL);
		ListNode *p1(NULL), *p2(NULL);
		while (head)
		{
			if (head->val < x)
			{
				if (!less)
				{
					p1 = head;
					less = p1;
				}
				else
				{
					p1->next = head;
					p1 = p1->next;
				}
			}
			else
			{
				if (!greater)
				{
					p2 = head;
					greater = p2;
				}
				else
				{
					p2->next = head;
					p2 = p2->next;
				}
			}
			head = head->next;	
		}
		if (p1)
			p1->next = greater;
		if (p2)
			p2->next = NULL;
		if (less)
			return less;
		else
			return greater;
    }
};
int main()
{
	ListNode a(1), b(4), c(3), d(2), e(5), f(2);
	a.next = &b; b.next = &c; c.next = &d; d.next = &e; e.next = &f;
	Solution sol;
	ListNode* res = sol.partition(&f, 1);
	while (res)
	{
		cout << res->val << " ";
		res = res->next;
	}
	return 0;
}