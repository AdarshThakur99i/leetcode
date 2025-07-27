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
        long long num1=0;
        long long num2=0;
        ListNode* p=l1;
        stack<int> st1;
        stack<int> st2;
        while(p!=NULL) {
           st1.push(p->val);

            p=p->next;
        }
        p=l2;
        while(p!=NULL) {
           st2.push(p->val);
            p=p->next;
        }
        int carry=0;
        ListNode* head=nullptr;
        p=head;
       while(!st1.empty() || !st2.empty() || carry) {
          int sum=carry;
          if(!st1.empty()){ sum+=st1.top(); st1.pop(); }
          if(!st2.empty()) {
            sum+=st2.top();
            st2.pop();
          }
        ListNode* node=new ListNode(sum%10);
        node->next=head;
        head=node;
          
          carry=sum/10;
       }
     

        return head;

    }
};