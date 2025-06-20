#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class DirectedGraphCycleDetection {
private:
    vector<vector<int>> adj;
    vector<int> color; // 0: white, 1: gray, 2: black
    
    bool dfsHasCycle(int node) {
        color[node] = 1; // Mark as gray (visiting)
        
        for (int neighbor : adj[node]) {
            if (color[neighbor] == 1) { // Back edge found
                return true;
            }
            if (color[neighbor] == 0 && dfsHasCycle(neighbor)) {
                return true;
            }
        }
        
        color[node] = 2; // Mark as black (visited)
        return false;
    }
    
public:
    DirectedGraphCycleDetection(int vertices) : adj(vertices), color(vertices, 0) {}
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    bool hasCycle() {
        for (int i = 0; i < adj.size(); i++) {
            if (color[i] == 0 && dfsHasCycle(i)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    DirectedGraphCycleDetection graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1); // Creates a cycle
    
    cout << "Graph has cycle: " << (graph.hasCycle() ? "Yes" : "No") << endl;
    return 0;
}
