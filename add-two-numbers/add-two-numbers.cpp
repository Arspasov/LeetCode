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
        if(!l1){
            return l2;
        }else if(!l2){
            return l1;
        }else{
            ListNode *newList = new ListNode();
                ListNode * current = newList;
            int carry = 0;
            while(l1 || l2 || carry){
                int sum = carry;
                if(l1){
                    sum+=l1->val;
                    l1=l1->next;
                }
                
                if(l2){
                    sum+=l2->val;
                    l2=l2->next;
                }
                
                if(sum>9){
                    carry = 1;
                }else{
                    carry  = 0;
                }
                
                ListNode *newNode = new ListNode(sum%10);
                current->next = newNode;
                current = current->next;
            }
            return newList->next;
        }
    }
};