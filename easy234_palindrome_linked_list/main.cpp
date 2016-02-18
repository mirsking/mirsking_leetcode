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
	// 1. 用快慢指针找到链表中点
	// 2. 将中点之后的链表反转
	// 3. 两个链表进行比较

    bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
			return true;

		ListNode *slow = head, *fast = head;
		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		//now slow is the mid node
		ListNode *last = slow->next;
		ListNode *pre = head;
		while (last->next)
		{
			ListNode* tmp = last->next;
			last->next = tmp->next;
			tmp->next = slow->next;
			slow->next = tmp;
		}

		while (slow->next)
		{
			slow = slow->next;	
			if (slow->val != pre->val)
				return false;
			pre = pre->next;
		}
		return true;
        
    }
};

int main()
{
	ListNode a(1), b(2), c(2), d(1);
	a.next = &b; b.next = &c; c.next = &d; //d.next = &e;
	Solution sol;
	cout << (sol.isPalindrome(&a) ? "True" : "False") << endl;
	return 0;
}