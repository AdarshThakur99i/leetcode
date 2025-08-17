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
    ListNode* doubleIt(ListNode* head) {
        string x="";
        ListNode* p=head;
        stack<int> st;
        while(p!=NULL) {
           st.push(p->val);

            p=p->next;
        }
        ListNode* newn=new ListNode(-1);
         p=newn;
        stack<ListNode*> st2;
        int carry=0;
        
        while(!st.empty() || carry) {
        
            int sum=(!st.empty()?st.top()*2:0) + carry;
            if(!st.empty()) st.pop();
             ListNode* temp=new ListNode(sum%10);
             st2.push(temp);
             carry=sum/10;
        }
        while(!st2.empty()) {
            p->next=st2.top();
            st2.pop();
            p=p->next;
        }
 
        return newn->next;
    }
};