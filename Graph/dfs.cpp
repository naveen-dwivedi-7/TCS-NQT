#include<bits/stdc++.h>
using namespace std;

unordered_map<int, list<int>>adj;

void addEdge(int u, int v, bool direction){
adj[u].push_back(v);
if(direction == 0) {
    adj[v].push_back(u); // For undirected graph, add the reverse edge
}
}
void printGraph(unordered_map<int, list<int>> &adj) {
    for(auto i : adj) {
        cout << i.first << " -> ";
        for(auto j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void dfs(int node ,unordered_map<int, bool> &visited) {
    visited[node] = true;
    cout << node << " ";
    for(auto neighbor:adj[node]){
        if(!visited[neighbor]){
            dfs(neighbor, visited);
        }
    }
}
int main(){
    int m,n;
    cout<<"Enter number of nodes: ";
    cin >> n;
    cout<<"Enter number of edges: ";
    cin >> m;

    for(int i=0;i<m;i++){
        int u,v;
        bool direction;
        cout<<"Enter edge (u, v) and direction (0/1): ";
        cin >> u >> v >> direction;
        addEdge(u,v,direction);
    }
    printGraph(adj);
    unordered_map<int, bool> visited;
    cout << "DFS Traversal: ";
    dfs(1, visited);
    return 0;
}