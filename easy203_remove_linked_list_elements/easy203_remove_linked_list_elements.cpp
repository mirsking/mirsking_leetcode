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
    ListNode* removeElements(ListNode* head, int val) {

		ListNode* head_bak = head;
		if (head == NULL)
			return NULL;

		while (head->val == val)
		{
			head = head->next;
			if (head == NULL)
			{
				head = head_bak;
				return NULL;
			}
		}

		ListNode* p = new ListNode(head->val);
		ListNode* res = p;
		head = head->next;

		while (head!=NULL)
		{
			if (head->val != val)
			{
				p->next = new ListNode(head->val);
				p = p->next;
			}
			head = head->next;
		}

		head = head_bak;
		return res;
    }
};

int main()
{
	ListNode a(1), b(2), c(3);
	//a.next = &b; b.next = &c;
	Solution sol;
	ListNode* re = sol.removeElements(&a, 1);
	return 0;
}