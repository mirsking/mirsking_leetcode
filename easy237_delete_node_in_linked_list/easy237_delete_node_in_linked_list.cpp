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
    void deleteNode(ListNode* node) {
		if (node == NULL || node->next == NULL)
			return;
		else
		{
			node->val = node->next->val;
			node->next = node->next->next;
		}
    }
};

int main()
{
	ListNode a(1), b(2), c(3);
	a.next = &b; b.next = &c;
	Solution sol;

	sol.deleteNode(&c);

	return 0;
}