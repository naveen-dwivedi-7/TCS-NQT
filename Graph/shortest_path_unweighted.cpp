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

void shortest_path_uwg(int s ,int d ,unordered_map<int, bool> &visited) {
 queue<int>q;
unordered_map<int, int> parent;

 q.push(s);
 visited[s] = true;
 parent[s] = -1; // Initialize parent of source as -1
 while(!q.empty()){
    int front=q.front();
    q.pop();
     for(auto i:adj[front])  {
         if(!visited[i]){
            visited[i] = true;
            q.push(i);
            parent[i] = front;
         }
    } 
 }
 vector<int> path;
 int current = d;
//  path.push_back(d);

 while (current != -1) {
    path.push_back(current);
    current = parent[current];
}

 reverse(path.begin(), path.end());
 cout << "Shortest path from " << s << " to " << d << ": ";
 for(auto node : path){
     cout << node << " ";
 }
 cout << endl;
}
int main(){
    int m,n;
    cin >> n;
    cin >> m;

    for(int i=0;i<m;i++){
        int u,v;
        bool direction;
        cin >> u >> v >> direction;
        addEdge(u,v,direction);
    }
    printGraph(adj);
    unordered_map<int, bool> visited;
    shortest_path_uwg(1, 8, visited);
    return 0;
}