#include <iostream>
#include <unordered_map>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;

        ListNode *res = NULL;
        ListNode *cur = head;
        bool cur_fail = false;
        while(cur && cur->next)
        {
            if(cur->next->val != cur->val)
            {
                if(!cur_fail)
                {
                    if(!res)
                        res = cur;
                    else
                        res->next = cur;
                    cur = cur->next;
                }
                else // cur_fail == true
                    cur_fail = false;
            }
            else
            {
                cur = cur->next;
                cur_fail = true;
            }
        }
        return res;
    }
};

int main()
{
    ListNode a(1), b(1), c(2), d(2), e(3);
    a.next = &b; b.next = &c; c.next = &d; d.next = &e;
    Solution sol;
    ListNode* res =sol.deleteDuplicates(&a);
    while(res)
    {
        cout << res->val << " ";
    }

    return 0;
}
