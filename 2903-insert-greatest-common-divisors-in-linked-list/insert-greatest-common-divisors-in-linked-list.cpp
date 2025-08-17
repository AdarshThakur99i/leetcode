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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
          ListNode* prev=nullptr;
          ListNode* p=head;
          while(p!=NULL) {
            if( p->next!=NULL) {
               ListNode* x=p->next;
               int gcD=gcd(p->val,x->val);
             ListNode* neww=new ListNode(gcD);
             p->next=neww;
             neww->next=x;
             p=p->next;
            }
            p=p->next;
            
          }
          return head;
    }
};