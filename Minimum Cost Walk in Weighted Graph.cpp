// There is an undirected weighted graph with n vertices labeled from 0 to n - 1.
// You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.
// A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.
// The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.
// You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.
// Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> parent(n), min_path_cost(n, -1);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find_root = [&](int node) {
            if (parent[node] != node) {
                parent[node] = find_root(parent[node]);
            }
            return parent[node];
        };

        for (auto& edge : edges) {
            int source = edge[0], target = edge[1], weight = edge[2];
            int source_root = find_root(source);
            int target_root = find_root(target);

            min_path_cost[target_root] &= weight;

            if (source_root != target_root) {
                min_path_cost[target_root] &= min_path_cost[source_root];
                parent[source_root] = target_root;
            }
        }

        vector<int> result;
        for (auto& q : query) {
            int start = q[0], end = q[1];
            if (start == end) {
                result.push_back(0);
            } else if (find_root(start) != find_root(end)) {
                result.push_back(-1);
            } else {
                result.push_back(min_path_cost[find_root(start)]);
            }
        }
        return result;
    }
};
