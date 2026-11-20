class MyHashMap {
public:

    struct node {
        int key;
        int val;
        node* next;
    };

    node* head;
    node* temp;

    MyHashMap() {
        head = new node();
        head->key = -1;
        head->val = -1;
        head->next = nullptr;

        temp = head;
    }

    void put(int key, int value) {

        // Check if key already exists
        node* n = head->next;

        while (n != nullptr) {
            if (n->key == key) {
                n->val = value;
                return;
            }

            n = n->next;
        }

        // Add new node
        node* t = new node();

        t->key = key;
        t->val = value;
        t->next = nullptr;

        temp->next = t;
        temp = t;
    }

    int get(int key) {

        node* n = head->next;

        while (n != nullptr) {

            if (n->key == key)
                return n->val;

            n = n->next;
        }

        return -1;
    }

    void remove(int key) {

        node* f = head->next;
        node* prev = head;

        while (f != nullptr) {

            if (f->key == key) {

                prev->next = f->next;

                if (f == temp)
                    temp = prev;

                delete f;
                return;
            }

            prev = f;
            f = f->next;
        }
    }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */