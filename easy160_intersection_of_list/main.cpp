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
	//˫ָ�뷨 http://blog.csdn.net/u012162613/article/details/41560337
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *p1 = headA;
		ListNode *p2 = headB;
		int lengthA = 0;
		int lengthB = 0;
		while (p1 || p2)
		{
			if (p1)
			{
				lengthA++;
				p1 = p1->next;
			}
			if (p2)
			{
				lengthB++;
				p2 = p2->next;
			}
		}

		// set p1 as the longer one
		int delta = 0;
		if (lengthA < lengthB)
		{
			p1 = headB;
			p2 = headA;
			delta = lengthB - lengthA;
		}
		else
		{
			p1 = headA;
			p2 = headB;
			delta = lengthA - lengthB;
		}
		while (delta--)
			p1 = p1->next;

		while (p1)
		{
			if (p1 == p2)
				return p1;
			else
			{
				p1 = p1->next;
				p2 = p2->next;
			}
		}
		return NULL;
    }
};

int main()
{
	ListNode a(1), b(2), c(3), d(4), e(5);
	a.next = &c; c.next = &d; d.next = &e;
	b.next = &d;
	Solution sol;
	ListNode* res = sol.getIntersectionNode(&a, &d);
	if (res)
		cout << res->val;
	else
		cout << "NULL";
	return 0;
}