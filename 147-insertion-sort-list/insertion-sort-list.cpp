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
    ListNode* insertionSortList(ListNode* head) {
        unordered_map<ListNode*,int> mp;

        ListNode* p=head;
        while(p!=NULL) {
            mp[p]=p->val;
            p=p->next;
        }
   
        
       vector<pair<ListNode*,int>> nodes(mp.begin(),mp.end());

       sort(begin(nodes),end(nodes),[](const auto& a,const auto& b) {
        return a.second<b.second;
       });
     int i=0;
        for( i=0; i<nodes.size()-1; i++) {
            nodes[i].first->next=nodes[i+1].first;
        }
        nodes[i].first->next=NULL;

        return nodes[0].first;


    }
};