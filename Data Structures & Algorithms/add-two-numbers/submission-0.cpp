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
        int carry=0, sum=0, val=0;
        ListNode* final_list= new ListNode(0); 
        ListNode* tail=final_list;
        while(l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            val = sum%10;
            
            tail->next = new ListNode(val);
            tail = tail->next;

            l1 = l1->next;
            l2 = l2->next;               
        }
        while(l1){
            sum = l1->val + carry;
            carry = sum/10;
            val = sum%10;

            tail->next = new ListNode(val);
            tail = tail->next;

            l1 = l1->next;
        }
        while(l2)
        {
            sum = l2->val + carry;
            carry = sum/10;
            val = sum%10;

            tail->next = new ListNode(val);
            tail = tail->next;
            
            l2 = l2->next;
        }
        if(carry){
            tail->next = new ListNode(carry);
            tail = tail->next;
        }

        return final_list->next;
    }
};
