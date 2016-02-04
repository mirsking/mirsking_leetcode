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
//1  2  3  4
//p1 x  p2  
//x  x  p1  x p2
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *p1=&dummy, *p2=&dummy;
		for (int i = 0; i < n; i++)
			p2 = p2->next;
		while (p2->next)
		{
			p1 = p1->next;
			p2 = p2->next;
		}

		p1->next = p1->next->next;
		return dummy.next;
	}
};

int main()
{
	ListNode a(1), b(2), c(3), d(4), e(5);
	a.next = &b; //b.next = &c; c.next = &d; d.next = &e;
	Solution sol;
	ListNode* res = sol.removeNthFromEnd(&a, 2);
	while (res)
	{
		cout << res->val << " ";
		res = res->next;
	}

	return 0;
}