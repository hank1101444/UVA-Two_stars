```cpp
#include<iostream>
using namespace std;
#include <vector>
#include <sstream>
#include <string>
#define maxN 25535
vector <int> graph[maxN];
int node_num, num, adj1, adj2, times;// 1~
stringstream ss;
string s, stp;

struct Node {
	int d=0;
	int low=0;
	int child_num=0;
	int par = -1;
	bool cut = false;
};

vector <Node> vertex;

void cutPoint (int u) {
	++times;
	vertex[u].d = times;
	vertex[u].low = times;
	for (int i = 0; i < graph[u].size(); ++i) {
		int v = graph[u][i];
		if (vertex[v].d == 0) {
			vertex[v].par = u;
			vertex[u].child_num++;
			cutPoint(v);
			vertex[u].low = min(vertex[u].low, vertex[v].low);
			// root 不是用此判斷
			if (vertex[u].par != -1) {
				if (vertex[v].low >= vertex[u].d) {
					//is cut point
					vertex[u].cut = true;
				}
			}
		}
		// check backedge
		else if (vertex[u].par != v) {
			vertex[u].low = min(vertex[v].d, vertex[u].low);
		}
	}
	// check root
	if (vertex[u].par == -1) {
		if (vertex[u].child_num > 1)
			vertex[u].cut = true;
	}
}

int main() {
	while (cin >> node_num && node_num != 0) {
		times = 0;
		for (int i = 1; i <= node_num; ++i) 
			graph[i].clear();
		vertex.assign(node_num + 1, Node());
		cin.ignore();
		while (getline(cin, s) && s !="0") {
			ss.str("");
			ss.clear();
			ss << s;
			bool bl_first = true;
			string stp;
			while (getline(ss, stp, ' ')) {
				num = stoi(stp);
				if (bl_first) {
					adj1 = num;
					bl_first = false;
				}
				else {
					adj2 = num;
					graph[adj1].push_back(adj2);
					graph[adj2].push_back(adj1);
				}
			}
		}
		for (int i = 1; i <= node_num; ++i) {		
			if(vertex[i].d ==0 )
				cutPoint(i);
		}
		int num = 0;
		for (int i = 1; i <= node_num; ++i) {
			if (vertex[i].cut)
				num += 1;
		}
		cout << num << '\n';
	}
	return 0;
}

```
