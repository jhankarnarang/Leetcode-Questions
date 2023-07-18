#include <unordered_map>

class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            moveToHead(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToHead(newNode);
            if (cache.size() > capacity) {
                Node* tailNode = removeTail();
                cache.erase(tailNode->key);
                delete tailNode;
            }
        }
    }
    
private:
    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    
    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }
    
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void addToHead(Node* node) {
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    
    Node* removeTail() {
        Node* tailNode = tail->prev;
        removeNode(tailNode);
        return tailNode;
    }
};
