class Solution {
public:
    void dfs(int node, int parent, vector<int> &depth, vector<vector<int>> &adj) {
        for (auto neighbor : adj[node]) {
            if (neighbor == parent) continue;
            depth[neighbor] = depth[node] + 1;
            dfs(neighbor, node, depth, adj);
        }
    }

    int diameter(vector<vector<int>> &edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> depth(n, 0);
        dfs(0, -1, depth, adj);

        int farthestNode = 0;
        for (int i = 0; i < n; ++i) {
            if (depth[i] > depth[farthestNode]) {
                farthestNode = i;
            }
        }

        fill(depth.begin(), depth.end(), 0);
        dfs(farthestNode, -1, depth, adj);

        return *max_element(depth.begin(), depth.end());
    }

    int minHeight(vector<vector<int>> &edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        int steps = 0;
        while (n > 2) {
            int s = q.size();
            n -= s;
            while (s--) {
                int x = q.front();
                q.pop();
                for (auto neighbor : adj[x]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
            steps++;
        }

        return n == 2 ? steps + 1 : steps;
    }
};
