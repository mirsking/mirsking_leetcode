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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1)
			return l2;
		if (!l2)
			return l1;
		ListNode *res = l1, *bak = l1;
		bool init = true;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				if (init)
					res = l1;
				else
					res->next = l1;
				l1 = l1->next;
			}
			else
			{
				if (init)
					res = l2;
				else
					res->next = l2;
				l2 = l2->next;
			}
			if (init)
			{
				bak = res;
				init = false;
			}
			else
			{
				res = res->next;
			}
		}
		if (l1)
			res->next = l1;
		if (l2)
			res->next = l2;

		return bak;
    }
};

int main()
{
	ListNode a(1), b(3), c(4);
	a.next = &b; b.next = &c;
	ListNode a1(2), b2(5), c2(6);
	a1.next = &b2; b2.next = &c2;
	Solution sol;
	ListNode* root = sol.mergeTwoLists(&a, &a1);
	return 0;
}