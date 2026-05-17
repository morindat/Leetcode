# include <unordered_map>
using namespace std;

// Problem 22
// LRU Cache: MEDIUM
// Date: 22/01/26

class Node {
public:
    int key, value;
    Node* next;
    Node* prev;

    Node (int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    Node* head;
    Node* tail;
    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // Not found
        if (mp.find(key) == mp.end()) return -1;

        // Grab the node
        Node* node = mp[key];

        // Remove from end, at begining
        removeNode(node);
        addNode(node);

        return node->value;

    }
    
    void put(int key, int value) {
        // case 1: key exists, replace the value
        if (mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->value = value;
            removeNode(node);
            addNode(node);
            return;
        }

        // node not in the map
        // create node with key, value
        // at key in the map add node
        // add not to the list too

        Node* node = new Node(key, value);
        mp[key] = node;
        addNode(node);

        // check overflow, ie capacity is full
        // remove the last node
        if (mp.size() > cap){
            Node* lru = popTail();   // least recently used
            mp.erase(lru->key);
            delete lru;
        }
    }

private:
    void addNode(Node* node){
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;

        p->next = n;
        n->prev = p;
    }

    Node* popTail() {
        Node* node = tail->prev;   // LRU
        removeNode(node);
        return node;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */