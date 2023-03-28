/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = nullptr;
        ListNode* tmp = nullptr;
        unsigned char carry = 0, num;
        
        while(l1 || l2)
        {
            num = l1 ? l1->val : 0;
            num += (l2 ? l2->val : 0);
            num += carry;
            carry = num / 10;
            /* first one */
            if (!l3)
            {
                l3 = tmp = new ListNode(num % 10);
            }
            else
            {
                tmp->next = new ListNode(num % 10);
                tmp = tmp->next;
            }
            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        if (carry)
        {
            tmp->next = new ListNode(carry);
        }
        return l3;
    }
};
