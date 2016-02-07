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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode dummy(-1);
		dummy.next = head;

		ListNode* prev = &dummy;
		for (int i = 0; i < m - 1; i++)
			prev = prev->next; //for case 1 2 3 4 5, prev is now at 1
		ListNode* head2 = prev; // head2 is 1

		prev = head2->next; //prev is 2
		ListNode* cur = prev->next;//cur is 3
		for (int i = m; i < n; i++)
		{
			prev->next = cur->next;
			cur->next = head2->next;
			head2->next = cur;
			cur = prev->next;
		}

		return dummy.next;
    }
};

int main()
{
	ListNode a(1), b(2), c(3), d(4), e(5);
	a.next = &b; b.next = &c; c.next = &d; d.next = &e;
	Solution sol;
	ListNode *res = sol.reverseBetween(&a, 2, 4);
	while (res)
	{
		cout << res->val << " ";
		res = res->next;
	}
	return 0;
}