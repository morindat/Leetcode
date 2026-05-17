# include <vector>
# include <queue>
# include <unordered_map>
using namespace std;

// Problem 69
// Problem 15 of March
// Clone Graph : MEDIUM
// Date: 08/03/26
// Complexity: O(V + E)

class Node {
public:
    int val;
    vector<Node*> neighbours;

    Node(){
        val = 0;
        neighbours = vector<Node*>();
    }

    Node(int _val){
        val = _val;
        neighbours = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbours){
        val = _val;
        neighbours = _neighbours;
    }
};

// DFS Approach
class Solution{
private:    
    unordered_map<Node*, Node*> cloned;

public:
    Node* cloneGraph(Node* node){
        // edge cases
        if (!node) return nullptr;

        // if node is cloned, return the cloned node
        if (cloned.find(node) != cloned.end()){
            return cloned[node];
        }

        // otherwise clone the node and its neighbs
        Node* clonedNode = new Node(node->val);
        cloned[node] = clonedNode;

        for (Node* neigh : node->neighbours){
            clonedNode->neighbours.push_back(cloneGraph(neigh));
        }

        return clonedNode;
    }

};

// BFS approach
class Solution{
public:
    Node* cloneGraph(Node* node){
        if (!node) return nullptr;

        unordered_map<Node*, Node*> cloned;
        
        // clone the first node
        Node* clonedNode = new Node(node->val);
        // add it to map so we do not try to clone it again
        cloned[node] = clonedNode;

        // as usual, our queue
        queue<Node*> q;
        q.push(node);

        while (!q.empty()){
            Node* curr = q.front();
            q.pop();

            // process the neighbours of that node
            for (Node* neigh: curr->neighbours){
                // see if we alr have a clone for it
                if (cloned.find(neigh) == cloned.end()){
                    // add the clone to map since we do not
                    cloned[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }

                // now add the cloned neigh to the current's node neighbours
                cloned[curr]->neighbours.push_back(cloned[neigh]);
            }
        }

        return clonedNode;
    }
};