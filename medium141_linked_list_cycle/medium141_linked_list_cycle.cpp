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
    bool hasCycle(ListNode *head) {
		if (head == NULL)
			return false;
		unordered_set<ListNode*> dict;
		while (head != NULL)
		{
			if (dict.find(head) == dict.end())
				dict.insert(head);
			else
				return true;
			head = head->next;
		}
		return false;
    }
};

int main()
{
	ListNode a(1), b(2), c(3), d(4);
	a.next = &b;
	b.next = &a;
	c.next = &d;
	//d.next = &b;
	Solution sol;
	cout <<	sol.hasCycle(&a);
	return 0;
}