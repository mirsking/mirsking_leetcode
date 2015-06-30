#include <iostream>
#include <unordered_set>
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
    ListNode *detectCycle(ListNode *head) {
		if (head == NULL)
			return NULL;
		unordered_set<ListNode*> dict;
		while (head != NULL)
		{
			if (dict.find(head) == dict.end())
				dict.insert(head);
			else
				return head;
			head = head->next;
		}
		return NULL;
    }
};


int main()
{
	ListNode a(1), b(2), c(3), d(4);
	a.next = &b;
	b.next = &c;
	c.next = &d;
//	d.next = &b;
	Solution sol;
	ListNode* res = sol.detectCycle(&a);
	return 0;
}