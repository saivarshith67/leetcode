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
    ListNode* reverseLinkedList(ListNode* prev, ListNode* curr)
    {
        if(!curr)
        {
            return prev;
        }
        ListNode* next = curr->next;
        curr->next = prev;

        ListNode* ans = reverseLinkedList(curr, next);
        return ans;
    }


    ListNode* doubleIt(ListNode* head) {
        if(!head)
        {
            return NULL;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;

        ListNode* reverse = reverseLinkedList(prev, curr);
        ListNode* temp = reverse;

        int carry = 0;
        int prod = 0;
        int digit = 0;
        while(temp->next)
        {
            prod = (temp->val * 2) + carry;
            digit = prod % 10;
            carry = prod / 10;
            temp->val = digit;
            temp = temp->next;
        }

        prod = (temp->val * 2) + carry;
        digit = prod % 10;
        carry = prod / 10;
        temp->val = digit;

        if(carry != 0)
        {
            temp->next = new ListNode(carry);
        }

        prev = NULL;
        curr = reverse;
        head = reverseLinkedList(prev, curr);

        return head;
        
    }
};