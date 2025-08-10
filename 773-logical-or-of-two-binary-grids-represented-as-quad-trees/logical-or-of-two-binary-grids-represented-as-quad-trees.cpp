/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isisisLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isisisLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isisisLeaf) {
        val = _val;
        isisLeaf = _isisLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isisLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isisLeaf = _isisLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:     
   
    Node* intersect(Node* quadTree1, Node* quadTree2) {
             
            if(quadTree1->isLeaf) {
                return  (quadTree1->val) ? new Node(true,true):quadTree2;
            }
            if(quadTree2->isLeaf) {
                return (quadTree2->val) ? new Node(true,true):quadTree1;
            }

            Node* topleft=intersect(quadTree1->topLeft,quadTree2->topLeft);
            Node* topright=intersect(quadTree1->topRight,quadTree2->topRight);
            Node* bottomleft=intersect(quadTree1->bottomLeft,quadTree2->bottomLeft);
            Node* bottomright=intersect(quadTree1->bottomRight,quadTree2->bottomRight);

            if(topleft->isLeaf && topright->isLeaf && bottomleft->isLeaf && bottomright->isLeaf && topleft->val==topright->val && topleft->val==bottomleft->val && topleft->val==bottomright->val) {
                      return new Node(topleft->val,true);
            }

            return new Node(false,false,topleft,topright,bottomleft,bottomright);
    }
};