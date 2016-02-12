#include <iostream>
#include <vector>
#include <climits>
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
	// merge sort
    ListNode* sortList(ListNode* head) {
		if (!head || !(head->next))
			return head;

		//快慢指针找到中间节点
		ListNode *slow = head, *fast = head;
		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		//split the list
		fast = slow;
		slow = slow->next;
		fast->next = NULL;
		ListNode *l1 = sortList(head);
		ListNode *l2 = sortList(slow);
		return mergeSortedList(l1, l2);
    }
private:
	ListNode* mergeSortedList(ListNode* l1, ListNode* l2)
	{
		ListNode dummy(-1);
		for (ListNode* p = &dummy; l1 || l2; p = p->next)
		{
			int val1 = l1 ? l1->val : INT_MAX;
			int val2 = l2 ? l2->val : INT_MAX;
			if (val1 <= val2)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
		}
		return dummy.next;
	}
};

int main()
{
	ListNode a(4), b(3), c(1), d(2);
	a.next = &b; b.next = &c; c.next = &d;
	Solution sol;
	ListNode* node = sol.sortList(&a);
	while (node)
	{
		cout << node->val << " ";
		node = node->next;
	}
	return 0;
}