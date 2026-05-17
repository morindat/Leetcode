#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Event {
    int x;
    int y1, y2;
    int type; // 1 for start, -1 for end
};

struct Node {
    int count;
    int length;
};

vector<int> ys;
vector<Node> tree;

void update(int node, int left, int right, int ql, int qr, int val) {
    if (ql >= right || qr <= left) return;
    
    if (ql <= left && right <= qr) {
        tree[node].count += val;
    } else {
        int mid = (left + right) / 2;
        update(node * 2, left, mid, ql, qr, val);
        update(node * 2 + 1, mid, right, ql, qr, val);
    }
    
    // Update length
    if (tree[node].count > 0) {
        tree[node].length = ys[right] - ys[left];
    } else if (right - left == 1) {
        tree[node].length = 0;
    } else {
        tree[node].length = tree[node * 2].length + tree[node * 2 + 1].length;
    }
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    
    int n;
    input >> n;
    
    vector<Event> events;
    
    // Read rectangles and collect y-coordinates
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        input >> x1 >> y1 >> x2 >> y2;
        
        // Add vertical edges as events
        events.push_back({x1, y1, y2, 1});  // left edge - start
        events.push_back({x2, y1, y2, -1}); // right edge - end
        
        // Collect y-coordinates for compression
        ys.push_back(y1);
        ys.push_back(y2);
    }
    
    // Sort events by x-coordinate, and for same x, process end events before start events
    // (to avoid counting area at rectangle boundaries incorrectly)
    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.type < b.type; // -1 (end) before 1 (start)
    });
    
    // Coordinate compression for y
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    
    // Initialize segment tree
    int m = ys.size() - 1;
    tree.resize(4 * m);
    
    long long totalArea = 0;
    int lastX = events[0].x;
    
    // Process events
    for (int i = 0; i < events.size(); i++) {
        int currentX = events[i].x;
        
        // Calculate area since last event
        int width = currentX - lastX;
        if (width > 0) {
            totalArea += (long long)width * tree[1].length;
        }
        
        // Process current event
        Event& e = events[i];
        
        // Convert y-coordinates to compressed indices
        int y1 = lower_bound(ys.begin(), ys.end(), e.y1) - ys.begin();
        int y2 = lower_bound(ys.begin(), ys.end(), e.y2) - ys.begin();
        
        // Update segment tree
        update(1, 0, m, y1, y2, e.type);
        
        lastX = currentX;
    }
    
    output << totalArea << endl;
    
    input.close();
    output.close();
    
    return 0;
}