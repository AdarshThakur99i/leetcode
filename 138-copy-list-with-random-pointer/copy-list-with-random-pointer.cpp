/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head) return NULL;
         Node* root=new Node(head->val);
       
          unordered_map<Node*,Node*> mp2;
     

    
          
        
      Node* p=head;
         Node* q=root;
         while(p!=NULL) {
       Node* x=new Node(p->val);
       if(p->random==NULL) {
        x->random=NULL;
       }

       
      

      
       q->next=x;
       
            
       q=x; 
     mp2[p]=q;
      
       p=p->next;
 
         }

         p=head;
         q=root->next;
         while(p!=NULL) {
            if(p->random !=NULL) {

                q->random=mp2[p->random];


                 
            }
 p=p->next;
 q=q->next;



         }
    



   return root->next;
         
    }
};