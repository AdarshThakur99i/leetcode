/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* p=node;
        ListNode* q=p;
        while(p!=NULL) {
         if(p->next!=NULL) {
            p->val=p->next->val;
        
         }
         else if(p->next==NULL) {
            q->next=NULL;
            break;
         }
         q=p;
         p=p->next;
        }
    }
};