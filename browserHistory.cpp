# include <stack>
# include <string>
using namespace std;

// Problem 23
// Browser History: MEDIUM
// Date: 23/01/26
// I was not in the mood at all, I just read the whole thing from Chat
// Might have to spin around a couple days later to check it out again

class BrowserHistory {
    stack<string> forwardd, backk;
    string current;
public:
    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        backk.push(current);
        current = url;
        while(!forwardd.empty()) forwardd.pop();
    }
    
    string back(int steps) {
        while (steps-- > 0 && !backk.empty()) {
            forwardd.push(current);
            current = backk.top();
            backk.pop();
        }
        return current;
    }
    
    string forward(int steps) {
        while (steps-- > 0 && !forwardd.empty()) {
            backk.push(current);
            current = forwardd.top();
            forwardd.pop();
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */