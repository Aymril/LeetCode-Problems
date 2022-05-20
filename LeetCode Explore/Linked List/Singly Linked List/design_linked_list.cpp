class MyLinkedList {
   private:
    struct Node {
        int data;
        Node* next;
        Node(int val, Node* link) {
            this->data = val;
            next = link;
        }
    };

    Node* head;
    int size;

   public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 or index >= size) return -1;
        Node* temp = head;
        while (--index >= 0) temp = temp->next;
        return temp->data;
    }

    void addAtHead(int val) {
        ++size;
        head = new Node(val, head);
    }

    void addAtTail(int val) {
        ++size;
        Node** result = &head;
        while (*result) result = &((*result)->next);
        *result = new Node(val, nullptr);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 or index > size) return;

        ++size;

        Node** result = &head;

        while (--index >= 0) result = &(*result)->next;

        *result = new Node(val, *result);
    }

    void deleteAtIndex(int index) {
        if (!head or index < 0 or index >= size) return;

        --size;
        Node** result = &head;

        while (--index >= 0) result = &(*result)->next;

        Node* removed = *result;
        *result = (*result)->next;
        delete removed;
    }
};

// second way

class MyLinkedList2 {
   private:
    struct Node {
        int data;
        Node* next;
        Node(int val, Node* link) {
            this->data = val;
            next = link;
        }
    };

    Node *head, *tail;
    int size;

   public:
    MyLinkedList2() {
        head = tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 or index >= size) return -1;

        Node* temp = head;

        while (--index >= 0) temp = temp->next;

        return temp->data;
    }

    void addAtHead(int val) {
        ++size;

        head = new Node(val, head);

        if (!head->next) tail = head;
    }

    void addAtTail(int val) {
        ++size;

        Node* node = new Node(val, nullptr);

        if (!head)
            head = node;
        else
            tail->next = node;

        tail = node;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 or index > size) return;

        ++size;

        Node** result = &head;

        while (--index >= 0) result = &(*result)->next;

        *result = new Node(val, *result);
        if (!(*result)->next) tail = *result;
    }

    void deleteAtIndex(int index) {
        if (index < 0 or index >= size) return;

        --size;

        Node **result = &head, *prev = nullptr;

        while (--index >= 0) {
            prev = *result;
            result = &(*result)->next;
        }

        Node* removed = *result;
        *result = (*result)->next;
        if (!*result) tail = prev;
        delete removed;
    }
};
