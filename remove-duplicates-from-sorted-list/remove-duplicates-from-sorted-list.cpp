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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return head;
        }
        
        ListNode* current = head;
        while(current->next !=NULL){
            if(current -> next->val == current->val){
                current->next = current->next->next;
            }else{
                current = current->next;
            }
        }
        return head;
    }
};

/*
if head == nullptr // size = 0;

if size == 1;
return head;

1->1->2
1,1,2
1->2
*/