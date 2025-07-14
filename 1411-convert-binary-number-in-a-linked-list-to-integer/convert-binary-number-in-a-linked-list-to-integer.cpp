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
    int getDecimalValue(ListNode* head) {
        string num="";
        while(head != NULL) {
                num+= to_string(head->val);
                head=head->next;
        }long long res=0;
        string binary =num;
        for(int i=0; i<binary.size(); i++) {
            if(binary[binary.size()-i-1]  == '1') {
                 res+= pow(2,i);
            }
        }
        return res;
    }
};