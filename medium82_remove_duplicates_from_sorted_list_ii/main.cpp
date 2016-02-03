#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <unordered_set>
#include <algorithm>
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
		if (!head || !head->next)
			return head;
		ListNode* p = head->next;
		if (head->val == p->val)
		{
			while (p && head->val == p->val)
			{
				ListNode* tmp = p;
				p = p->next;
				delete tmp;
			}
			delete head;
			return deleteDuplicates(p);
		}
		else
		{
			head->next = deleteDuplicates(head->next);
			return head;
		}
    }
};

int main()
{
	ListNode a(1), b(1), c(2), d(2), e(3), f(4), g(4), h(5);
    a.next = &b; b.next = &c; c.next = &d; d.next = &e;
	e.next = &f; f.next = &g; g.next = &h;
    Solution sol;
    ListNode* res =sol.deleteDuplicates(&a);
    while(res)
    {
        cout << res->val << " ";
		res = res->next;
    }

    return 0;
}
