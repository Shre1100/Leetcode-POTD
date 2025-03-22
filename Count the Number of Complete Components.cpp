// You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.
// Return the number of complete connected components of the graph.
// A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
// A connected component is said to be complete if there exists an edge between every pair of its vertices.
//Concept used --> BFS, Graph
class Solution {
private:
    void bfs(int node,vector<vector<int>> &adj,vector<int> &comp,vector<bool> &vis){
        queue<int> q;
        q.push(node);
        vis[node]=true;

        while(!q.empty()){
            int n=q.front();
            q.pop();
            comp.push_back(n);
            for(auto it:adj[n]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=true;
                }
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){

            if(!vis[i]){
                vector<int> comp;
                bfs(i,adj,comp,vis);
                bool iscomp=true;
                for(auto it: comp){
                    if(adj[it].size()!=comp.size()-1){
                        iscomp=false;
                        break;
                    }
                }
                if(iscomp)ans++;
            }
        }
        return ans;
    }
};
