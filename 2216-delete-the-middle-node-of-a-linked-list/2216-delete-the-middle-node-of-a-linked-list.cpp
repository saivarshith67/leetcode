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
    ListNode* deleteMiddle(ListNode* head) 
    {
        if(head->next == NULL)
        {
            //single element;
            return NULL;
        }
        if(head == NULL)
        {
            return NULL;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slowPrev = NULL;

        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;
                slowPrev = slow;
                slow = slow->next;
            }
        }
        //slow is on the middle element;
        slowPrev->next = slow->next;
        slow->next = NULL;
        delete slow;

        return head;

        
    }
};