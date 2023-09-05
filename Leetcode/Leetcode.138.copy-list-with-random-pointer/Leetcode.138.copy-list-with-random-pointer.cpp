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

class Solution { // Independently solved
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        Node* curr(head);
        Node* new_head(nullptr);
        Node** head_p(&new_head);
        while (curr != nullptr) {
            *head_p = new Node(curr->val);
            Node* new_curr(*head_p);
            new_curr->random = curr->random;
            mp.insert(pair<Node*, Node*>(curr, new_curr));
            head_p = &(new_curr->next);
            curr = curr->next;
        }
        Node* new_curr(new_head);
        while (new_curr != nullptr) {
            if (new_curr->random != nullptr) {
                new_curr->random = mp.at(new_curr->random);
            }
            new_curr = new_curr->next;
        }
        return new_head;
    }
};