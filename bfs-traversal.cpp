#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <list>
#include <pair>
using namespace std;

void helper(unordered_map<int, list<int>> adjList, vector<int> &ans, int node, unordered_map<int, bool> &visited){
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto i : adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges){

    //prepare adjList
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> ans;
    unordered_map<int, bool> visited;
    for(int i = 0; i<vertex; i++){
        if(!visited[i]){
            helper(adjList, ans, i, visited);
        }
    }                 
}


