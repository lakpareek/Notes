void dfs(int node, vector<bool> &visited, unordered_map<int, list<int>> &adjList, vector<int> &component){
    component.push_back(node);
    visited[node] = true;

    for(auto i : adjList[node]){
        if(!visited[i]){
            dfs(i, visited, adjList, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int vertex, int E, vector<vector<int>> &edges){
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    vector<bool> visited(vertex, false);
    for(int i = 0; i<vertex; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }
    return ans;
}


/*The specific implementation of the depth-first search (DFS) function can vary depending on the requirements and preferences of the platform or problem you are working with. Both forms, vector<vector<int>> and vector<int>, are valid and can be used depending on the desired output.

In the above code, the DFS function is implemented to return a vector<vector<int>>. This means that it will find all the connected components in the graph and return them as separate vectors, where each inner vector represents a connected component.

However, if you prefer a different form where the DFS function returns a single vector that contains all the nodes visited during the traversal, you can modify the code accordingly.

Here's an example of how you can modify the code to return a single vector instead of a vector of vectors:*/


void helper(unordered_map<int, list<int>>& adj, int node, vector<bool>& visited, vector<int>& nodes) {
    visited[node] = true;
    nodes.push_back(node);

    for (auto i : adj[node]) {
        if (!visited[i]) {
            helper(adj, i, visited, nodes);
        }
    }
}

vector<int> depthFirstSearch(int V, int E, vector<vector<int>>& edges) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);
    vector<int> nodes;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            helper(adj, i, visited, nodes);
        }
    }

    return nodes;
}
