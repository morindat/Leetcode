# include <iostream>
using namespace std;

// Problem 21
// Split Linked List In Parts: HARD MEDIUM
// Date: 21/01/26

class Node {
public:
    int val;
    Node* next;
    
    Node (int x) : val(x), next(nullptr) {}
};

class MyLinkedList {
public:
    Node* head;
    int size;

    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        // break points, head is null or index is >= size
        // we index from 0 to size-1, if given index = size, we are out bounds already no need to check
        if (index < 0 || index >= size) return -1;

        Node* temp = head;
        int i = 0;

        while (temp && i < index){
            i++;
            temp = temp->next;
        }

        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        if (head == nullptr){
            Node* newNode = new Node(val);
            head = newNode;
            size++;
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        while (temp->next){
            temp = temp->next;
        }

        temp->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        if (index == 0){
            addAtHead(val);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < index; i++){
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < index; i++) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */