class Solution {

#define i_d pair <int, double>
#define d_i pair <double, int>
    static const int Mx = 20010;
    priority_queue <d_i> pq;

public:
    vector <i_d> v[Mx];
    double D[Mx];
    bool visit[Mx];


    void init(int n) {
        for (int i = 0; i < n; ++i) {
            v[i].clear();
            D[i] = 0;
        }
        memset(visit, 0, sizeof(visit));
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for (int i = 0; i < edges.size(); ++i) {
            v[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            v[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        dijkstra(start);
        return D[end];
    }
    void dijkstra(int start) {
        D[start] = 1;
        pq.push(make_pair(D[start], start));
        while (!pq.empty()) {
            int cur_node = pq.top().second;
            double cur_weight = pq.top().first;
            pq.pop();
            visit[cur_node] = 1;
            for (int i = 0; i < v[cur_node].size(); ++i) {
                int nx_node = v[cur_node][i].first;
                double edge_weight = v[cur_node][i].second;
                if (!visit[nx_node] && cur_weight * edge_weight >= D[nx_node]) {
                    D[nx_node] = cur_weight * edge_weight;
                    pq.push(make_pair(D[nx_node], nx_node));
                }
            }
        }
    }

};
