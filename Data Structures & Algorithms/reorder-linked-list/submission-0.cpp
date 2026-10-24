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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* null_ptr = NULL;
        ListNode* tmp_1 = head;
        ListNode* tmp_2 = head->next;

        while(tmp_2 != NULL)
        {
            tmp_1->next = null_ptr;
            null_ptr = tmp_1;
            tmp_1 = tmp_2;
            tmp_2 = tmp_2->next;
        }
        tmp_1->next = null_ptr;
        return tmp_1;
    }

    void reorderList(ListNode* head) {
    if (!head || !head->next)
        return;

    // Find middle
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list
    ListNode* l1 = head;
    ListNode* l2 = slow->next;
    slow->next = nullptr;

    // Reverse second half
    l2 = reverseList(l2);

    // Merge
    while (l1 && l2) {
        ListNode* fwd_1 = l1->next;
        ListNode* fwd_2 = l2->next;

        l1->next = l2;
        l2->next = fwd_1;

        l1 = fwd_1;
        l2 = fwd_2;
    }
}
};
