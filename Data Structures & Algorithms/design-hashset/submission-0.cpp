class MyHashSet {
public:
    struct node {
        int val;
        node* next;
    };

    node* head;
    node* temp;

    MyHashSet() {
        temp = new node();
        temp->val = -1;
        temp->next = nullptr;

        head = temp;
    }

    void add(int key) {
        // Don't add duplicate
        if (contains(key))
            return;

        node* n = new node();
        n->val = key;
        n->next = nullptr;

        temp->next = n;
        temp = temp->next;
    }

    void remove(int key) {
        node* f = head->next;
        node* prev = head;

        while (f != nullptr) {
            if (f->val == key) {
                prev->next = f->next;

                // If deleting the last node,
                // update temp
                if (f == temp)
                    temp = prev;

                delete f;
                return;
            }

            prev = f;
            f = f->next;
        }
    }

    bool contains(int key) {
        node* f = head->next;

        while (f != nullptr) {
            if (f->val == key)
                return true;

            f = f->next;
        }

        return false;
    }
};