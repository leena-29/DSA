#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TopologicalSort {
private:
    vector<vector<int>> adj;
    vector<int> indegree;
    int vertices;
    
public:
    TopologicalSort(int v) : vertices(v), adj(v), indegree(v, 0) {}
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        indegree[v]++;
    }
    
    vector<int> kahnsAlgorithm() {
        vector<int> result;
        queue<int> q;
        
        // Add all vertices with indegree 0 to queue
        for (int i = 0; i < vertices; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);
            
            // Reduce indegree of adjacent vertices
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // Check if there's a cycle
        if (result.size() != vertices) {
            result.clear(); // Return empty vector if cycle exists
        }
        
        return result;
    }
};

int main() {
    TopologicalSort graph(6);
    graph.addEdge(5, 2);
    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    
    vector<int> result = graph.kahnsAlgorithm();
    
    if (result.empty()) {
        cout << "Graph has a cycle!" << endl;
    } else {
        cout << "Topological Sort: ";
        for (int vertex : result) {
            cout << vertex << " ";
        }
        cout << endl;
    }
    
    return 0;
}
