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
void insertcopyInbetween( Node* head) {
    Node* temp  = head;
    while( temp != NULL){
        Node* nextelement =  temp->next;
        Node* copy = new Node(temp->val);

        copy->next = nextelement;
        temp->next = copy;

        temp = nextelement; 
    }
}
void connectrandompointer(Node* head){
    Node* temp = head;
    while( temp != NULL){
        Node* copyNode  = temp->next;

        if( temp->random){
         copyNode->random = temp->random->next;
        } 
        else {
        copyNode->random = nullptr;
        }
        temp = temp->next->next;
    }
}
Node* getDeepcopyList( Node* head){
    Node* temp = head;
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    while( temp != NULL){
        // creating new list
        res->next = temp->next;
        res = res->next;

        // disconnecting and going back to
        // inital state of the ll
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;
}
    Node* copyRandomList(Node* head) {
        insertcopyInbetween(head);
        connectrandompointer(head);
        return getDeepcopyList(head);

    }
};