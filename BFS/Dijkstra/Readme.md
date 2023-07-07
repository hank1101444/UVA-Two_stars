```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
const int mxN = 20010;
#define p pair<int, int>
vector <p> edges[mxN];
int D[mxN];
int node_num, edge_num, u, v, w, start, End;
bool check[mxN];
//最長路徑
priority_queue<p> pq;

//最短路徑
//priority_queue<p, vector<p>, greater<p>> pq;

void dijkstra(int start) {
	D[start] = 0;
	pq.push(make_pair(D[start], start));
	while (!pq.empty()) {
		int current_node = pq.top().second;
		int node_w = pq.top().first;
		check[current_node] = true;
		pq.pop();
		for (int i = 0; i < edges[current_node].size(); ++i) {
			int nx_node = edges[current_node][i].first;
			int edge_weight = edges[current_node][i].second;
			if (!check[nx_node] && edge_weight + current_node < D[nx_node] //最長：>) {	//有找到更小的該點就持續push 進去, 如果已經卻認為最小(已pop過)或不能變更小就不會進去
				D[nx_node] = node_w + edge_weight;
				pq.push(make_pair(D[nx_node], nx_node));//一個點可能被重複push 進去好幾次
			}
		}
	}

}



void init() {
	for (int i = 0; i < node_num; ++i) {
		edges[i].clear();
		D[i] = INT_MAX;
		//最長
		//D[i] = 0;

	}
	memset(check, 0, sizeof(check));
}


int main() {
	cin >> node_num >> edge_num >> start >> End;
	init();
	for (int i = 0; i < edge_num; ++i) {
		cin >> u >> v >> w;
		edges[u].push_back(make_pair(v, w));
		edges[v].push_back(make_pair(u, w));
	}

	dijkstra(start);
	cout << D[End] << endl;
/*
4 5 0 3
0 2 2
0 1 5
2 1 3
2 3 9
1 3 0
*/

	return 0;
}
```
