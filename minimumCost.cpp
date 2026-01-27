class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> outgoing(n);
        vector<vector<pair<int, int>>> incoming(n);
        
        for (auto& e : edges) {
            outgoing[e[0]].push_back({e[1], e[2]});
            incoming[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        dist[0] = 0;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            
            if (cost > dist[u]) continue;
            
            for (auto [v, w] : outgoing[u]) {
                if (cost + w < dist[v]) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
            
            for (auto [v, w] : incoming[u]) {
                if (cost + 2 * w < dist[v]) {
                    dist[v] = cost + 2 * w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist[n-1] == INT_MAX ? -1 : dist[n-1];
    }
};