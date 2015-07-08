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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		int carry = 0;
		ListNode* pNode = NULL, *pNext = NULL, *pRoot = NULL;
		while (l1 != NULL || l2 != NULL)
		{
			if (l1 == NULL)
			{
				pNext = new ListNode(l2->val + carry);
				l2 = l2->next;
			}
			else if (l2 == NULL)
			{
				pNext = new ListNode(l1->val + carry);
				l1 = l1->next;
			}
			else
			{
				pNext = new ListNode(l1->val + l2->val + carry);
				l1 = l1->next;
				l2 = l2->next;
			}

			carry = pNext->val / 10;
			pNext->val = pNext->val % 10;
			
			if (pRoot == NULL)
			{
				pRoot = pNode = pNext;
			}
			else
			{
				pNode->next = pNext;
				pNode = pNext;
			}
		}

		if (carry != 0)
		{
			pNext = new ListNode(carry);
			pNode->next = pNext;
		}
		return pRoot;
    }
};

int main()
{
	ListNode a(5), b(4), c(3),
		d(5), e(6), f(4);
	//a.next = &b;// b.next = &c;
	//d.next = &e; e.next = &f;
	Solution sol;
	ListNode* res = sol.addTwoNumbers(&a, &d);
	return 0;
}