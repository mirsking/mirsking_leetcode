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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;

        ListNode* tail = head;
        int N = 0;
        while(tail)
        {
            N++;
            tail = tail->next;
        }
        k = k % N;
        int rot_index = (N - k)%N;
        cout << "rot_index: " << rot_index << endl;

        ListNode* res = head;
        ListNode* res_parent = head;
        while(rot_index > 0)
        {
            res_parent = res;
            res = res->next;
            rot_index --;
        }

        if(res == res_parent) // means origin rot_index = 0
            return res;

        res_parent->next = NULL;
        tail = res;
        while(tail->next)
            tail = tail->next;
        tail->next = head;
        return res;
    }
};

int main()
{

    ListNode a(1), b(2), c(3), d(4), e(5);
    a.next = &b; b.next = &c; c.next = &d; d.next = &e;
    Solution sol;
    ListNode* res = sol.rotateRight(&a, 4);
    while(res)
    {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}
