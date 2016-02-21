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
    ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next)
			return head;

		ListNode* odd = head, *even = head->next;
		ListNode* podd = odd, *peven = even;
		head = head->next->next;
		int count = 0;
		while (head)
		{
			count++;
			if (count % 2 != 0) // odd
			{
				podd->next = head;
				podd = podd->next;
			}
			else
			{
				peven->next = head;
				peven = peven->next;	
			}
			head = head->next;
		}
		peven->next = NULL;
		podd->next = even;
		return odd;
    }
};

int main()
{
	ListNode a(1), b(2), c(3), d(4), e(5);
	a.next = &b; b.next = &c; c.next = &d, d.next = &e;
	Solution sol;
	ListNode* res = sol.oddEvenList(&a);
	while (res)
	{
		cout << res->val << " ";
		res = res->next;
	}
	return 0;
}