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
    void reorderList(ListNode* head) {
		ListNode* node = head;
		int n = 0;
		while (node)
		{
			n++;
			node = node->next;
		}
		if (n < 3)
			return;
		int right = n / 2;
		int left = n - right;

		//go to right head node and make the left final node's next to be NULL
		node = head;
		for (int i = 0; i < left-1; i++)
		{
			node = node->next;
		}
		ListNode* tmp = node;
		node = node->next;
		tmp->next = NULL;

		
		//node now point to the right first, reverse the link list
		ListNode* final_head = NULL;
		while (node)
		{
			ListNode* tmp = node->next;
			node->next = final_head;
			final_head = node;
			node = tmp;
		}

		//now merge final_head and head
		node = head;
		while (node && final_head)
		{
			ListNode* tmp = node->next;
			node->next = final_head;
			node = tmp;

			tmp = final_head->next;
			final_head->next = node;
			final_head = tmp;
		}
    }
};

int main()
{
	ListNode a(1), b(2), c(3), d(4), e(5);
	//a.next = &b; //b.next = &c; //c.next = &d; d.next = &e;
	Solution sol;
	sol.reorderList(NULL);
	ListNode* node = &a;
	while (node)
	{
		cout << node->val << " ";
		node = node->next;
	}
	return 0;
}