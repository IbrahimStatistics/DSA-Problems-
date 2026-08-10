/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return NULL;

        Node* curr = head;
        while(curr!=nullptr) {
            if(curr->child!=nullptr) {
                // Flatten the child nodes
                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;

                // Find Tail
                while(curr->next!=nullptr) {
                    curr = curr->next;
                }

                // Attach Tail with next ptr
                if(next!=nullptr) {
                    curr->next = next;
                    next->prev = curr;
                }
            }

            curr = curr->next;
        }        

        return head;
    }
};