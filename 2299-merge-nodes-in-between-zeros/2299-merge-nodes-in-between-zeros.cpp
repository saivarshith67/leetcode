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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode* temp1 = head;
        ListNode* resultHead = new ListNode(-1);
        ListNode* temp = resultHead;
        temp1 = temp1->next;
        while(temp1)
        {
            if(temp1->val == 0)
            {
                temp->next = new ListNode(sum);
                sum = 0;
                temp = temp->next;
            }
            else
            {
                sum += temp1->val;
            }
            temp1 = temp1->next;

        }
        resultHead = resultHead->next;
        return resultHead;
    }
};