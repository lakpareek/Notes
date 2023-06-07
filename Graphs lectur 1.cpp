#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (direction == 0)
            adj[v].push_back(u);
    }

    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << "->";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges: " << endl;
    cin >> m;

    Graph g;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Creating an Undirected graph
        g.addEdge(u, v, 12);
    }
    
    // Printing the graph
    g.printAdjList();
    
    return 0;
}


unordered_map<int, list<int> > adj; 
for(int i=0; i<m; i++) { 
    int u= edges [i][0]; 
    int v=edges [i] [1];
    adj [u].push_back(v); 
    adj [v].push_back(u)
}