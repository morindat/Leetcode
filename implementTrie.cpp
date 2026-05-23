# include <string>
# include <unordered_map>
using namespace std;

/**
 * Problem 137
 * Problem 24/45 of May 2026
 * Implement Trie: MEDIUM
 * Date: 23/05/26
 * Time Complexity: O(n); 
 * Where n really is just the length of the word
 */

class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode() {
        isEnd = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;

        for (char c : word) {
            int indx = c - 'a';
            if (!current->children[indx]) {
                current->children[indx] = new TrieNode();
            }
            current = current->children[indx];
        }
        current->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;

        for (char c : word) {
            int indx = c - 'a';
            if (!current->children[indx]) {
                return false;
            }
            current = current->children[indx];
        }
        return current->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;

        for (char c : prefix) {
            int indx = c - 'a';
            if (!current->children[indx]) {
                return false;
            }
            current = current->children[indx];
        }
        return true;
    }
};

// Using a hashmap: memory efficient

class TrieNode_h {
public:
    bool isEnd;
    unordered_map<char, TrieNode_h*> children;

    TrieNode_h() : isEnd(false) {}
};

class Trie_h {
private:
    TrieNode_h* root;

public:
    Trie_h() {
        root = new TrieNode_h();
    }

    void insert_h(string word) {
        TrieNode_h* current = root;

        for (char c : word) {
            if (!current->children.count(c)) {
                current->children[c]= new TrieNode_h();
            }
            current = current->children[c];
        }
        current->isEnd = true;
    }

    bool search_h(string word) {
        TrieNode_h* current = root;

        for (char c : word) {
            if (!current->children.count(c)) {
                return false;
            }
            current = current->children[c];
        }
        return current->isEnd;
    }

    bool startsWith_h(string prefix) {
        TrieNode_h* current = root;

        for (char c : prefix) {
            if (!current->children.count(c)) {
                return false;
            }
            current = current->children[c];
        }
        return true;
    }
};