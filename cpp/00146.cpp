class LRUCache {
    struct Node {
        Node *prev, *next;
        int key, val;
    };
    
    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail;
    
    void remove_node(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void push_back_node(Node* node) {
        node->next = tail;
        node->prev = tail->prev;
        tail->prev = node;
        node->prev->next = node;
    }
public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        
        remove_node(cache[key]);
        push_back_node(cache[key]);
        
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end())
            cache[key] = new Node;
        else remove_node(cache[key]);
        
        cache[key]->key = key;
        cache[key]->val = value;
        push_back_node(cache[key]);
        
        if (cache.size() > capacity) {
            cache.erase(head->next->key);
            remove_node(head->next);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

