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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* sum = new ListNode(-1);
        ListNode* ans = sum;
        int carry = 0;
        int totalSum = 0;
        int digit = 0;
        while(temp1 && temp2)
        {
            totalSum = temp1->val + temp2->val + carry;
            digit = totalSum % 10;
            carry = totalSum / 10; 
            sum->next = new ListNode(digit);
            temp1 = temp1->next;
            temp2 = temp2->next;
            sum = sum->next;
        }
        while(temp2)
        {
            totalSum = temp2->val + carry;
            digit = totalSum % 10;
            carry = totalSum / 10;
            sum->next = new ListNode(digit);
            temp2 = temp2->next;
            sum = sum->next;
        }
        while(temp1)
        {
            totalSum = temp1->val + carry;
            digit = totalSum % 10;
            carry = totalSum / 10;
            sum->next = new ListNode(digit);
            temp1 = temp1->next;
            sum = sum->next;
        }
        if(carry != 0)
        {
            sum->next = new ListNode(carry);
            sum = sum->next;
        }

        
        
        return ans->next;
    }
};