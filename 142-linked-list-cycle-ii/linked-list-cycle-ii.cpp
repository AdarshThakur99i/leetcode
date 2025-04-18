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
    ListNode *detectCycle(ListNode *head) {
         ListNode* p=head;

         unordered_map<ListNode*,bool> mp;

          while(p!=NULL) {
            if(mp[p]==true) {
              return p;

            }
            mp[p]=true;
            p=p->next;
          }

          return NULL;
        
    }
};