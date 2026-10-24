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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next)
        return nullptr;

        ListNode *trav = head;
        int len=0;
        while(trav){
            trav = trav->next;
            len++;
        }
        if(len==n){
            head = head->next;
            return head;
        }
        int from_start = len-n-1;
        cout<<from_start;
        trav = head;
        while(from_start--)
        {
            cout<<"Hello";
            trav = trav->next;
        }
        trav->next = trav->next->next;

        return head;
    }
};
