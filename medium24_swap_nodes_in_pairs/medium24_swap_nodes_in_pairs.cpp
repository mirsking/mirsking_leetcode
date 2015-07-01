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
    ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* new_head = head->next;
		ListNode* next_head = head->next->next;
		head->next->next = head;
		head->next = swapPairs(next_head);
		head = new_head;
		return head;
    }
};

int main()
{
	ListNode a(1), b(2), c(3), d(4);
	a.next = &b; b.next = &c; c.next = &d;
	Solution sol;
	ListNode* res = sol.swapPairs(&b);

	return 0;
}