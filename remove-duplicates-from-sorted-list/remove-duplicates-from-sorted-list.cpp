/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode* newHead = new ListNode(head-> val);
        ListNode* tail = newHead;
        //1_a->1_b->2
        //1->2
        while(head){
            //nullptr
            if(head->val != tail ->val){
                tail->next = new ListNode(head -> val);
                tail = tail ->next;
            }
            head = head->next;
        }
        
        return newHead;
    }
};
​
/*
if head == nullptr // size = 0;
​
if size == 1;
return head;
​
1->1->2
1,1,2
1->2
*/
