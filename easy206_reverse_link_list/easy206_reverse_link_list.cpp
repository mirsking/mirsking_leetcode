#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL)
			return NULL;

		ListNode* next_node = head->next;
		head->next = NULL;
		while (next_node != NULL)
		{
			ListNode* tmp = head;
			head = next_node;
			next_node = head->next;
			head->next = tmp;
		}
		return head;
	}
};


int main(int argc, char** argv)
{
	ListNode a(10), b(11), c(12), d(9);
	//a.next = &b;
	//b.next = &c;
	//c.next = &d;

	ListNode* tmp = &a;
	while (tmp->next != NULL)
	{
		cout << tmp << endl;
		tmp = tmp->next;
	}

	Solution sol;
	ListNode* x = sol.reverseList(&a);

	cout << endl;

	tmp = x;
	while (tmp->next != NULL)
	{
		cout << tmp << endl;
		tmp = tmp->next;
	}


	return 0;
}