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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return head;

		ListNode* head_bak = head;
		unordered_set<int> exist_nodes;
		exist_nodes.insert(head->val);
		ListNode* lastnode = head;
		head = head->next;

		while (head != NULL)
		{
			if (exist_nodes.find(head->val) != exist_nodes.end())
			{
				lastnode->next = head->next;
				head = head->next;
			}
			else
			{
				exist_nodes.insert(head->val);
				lastnode = lastnode->next;
				head = head->next;
			}
		}
		return head_bak;
	}
};

int main()
{
	Solution sol;
	ListNode a(0), b(0), c(0), d(2), e(2);
	a.next = &b; b.next = &c; c.next = &d; d.next = &e;
	ListNode* root = sol.deleteDuplicates(&a);
	return 0;
}