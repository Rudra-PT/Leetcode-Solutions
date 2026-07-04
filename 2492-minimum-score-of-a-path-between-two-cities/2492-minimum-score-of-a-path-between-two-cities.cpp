class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int distance = road[2];
            graph[u].push_back({v, distance});
            graph[v].push_back({u, distance});
        }

        queue<int> q;
        vector<bool> visited(n + 1, false);
        
        q.push(1);
        visited[1] = true;
        
        int min_score = INT_MAX;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
        
            for (const auto& neighbor : graph[current]) {
                int next_city = neighbor.first;
                int distance = neighbor.second;
    
                min_score = min(min_score, distance);
                if (!visited[next_city]) {
                    visited[next_city] = true;
                    q.push(next_city);
                }
            }
        }
        
        return min_score;
    }
};