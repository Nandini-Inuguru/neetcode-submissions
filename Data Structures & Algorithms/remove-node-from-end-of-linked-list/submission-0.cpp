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
        ListNode* first=head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* second = &dummy;
        int count=0;
        while(first && count<n){
            first=first->next;
            count++;
        }
        while(first){
            first=first->next;
            second=second->next;
        }
        second->next=second->next->next;
        return dummy.next;
    }
};
