// Listenin node yapisi
struct Node {
    int val;
    Node* next;
};

// cozum 1
Node* cycleNode(Node* head) {
        Node* slow = head, *fast = head;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return slow;
        }
        return nullptr;
}

Node* detectCycle(Node*head) {
        Node* cycled = cycleNode(head);
        
        if(!cycled) return nullptr;
        
        while(head != cycled) {
            cycled = cycled->next;
            head = head->next;
        }
        return head;
}

// burada cozum 1 daha optimal sekilde yazilmaya calisilmistir. Kodda duzenleme yapilmistir, mantik kisminda degisiklik olmamistir.
Node *detectCycle(Node *head) {
        Node* slow = head, *fast = head;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                while(head != slow) {
                    head = head->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
}
