
### 有一個小鎮，裡面的居民每個人都只會給另一個人寄信，求把信寄給哪位居民可以讓最多人看到這封信，若有相同者則取較小者。   

### Input： 第一行為一整數 T，代表有 T 組測資，每組測資的第一行為一整數 N，接下來 N 行每行都有兩個整數 u、v，代表居民 u 會把信寄給居民 v。

### Output： 輸出寄信給誰可以讓最多的居民看到這封信，若有相同者則取較小者。

## 解題思路    
### DFS 模擬即可，由於會 TLE，所以進行一點剪枝，多使用一個陣列紀錄某位居民是否已經被模擬過了，若在前面被模擬過了則就不需要在模擬第一個寄信給這位居民了，因為前面模擬的是另一個居民會寄給這位居民，一定會比直接寄信給這位居民的人數還要多

## Problem : why bool faster than int??
## error : 假設 N = 100 居民為 1  ~ 100 位 我只創 0 ~ 99 所以要+1 
## TLE : 因為如果 i 在前面被做過一次那就不用再做一次了，因為前面是從某個人寄到 i， 一定會比直接寄到 i 還要多人  

```cpp
if (duplicate[i] != 1) {	// TLE
```    

# code
```cpp
#include <iostream>
using namespace std;
#include <vector>
#include <cstring>
const int mxN = 50010;
vector <int> graph[mxN];
bool visit[mxN], duplicate[mxN];
int tp, T, u, v, N, kase = 1;

void init(int n) {
	for (int i = 1; i<= n; ++i) {
		graph[i].clear();
	}
	memset(visit, 0, sizeof(visit));
	memset(duplicate, 0, sizeof(duplicate));

}

void fast() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}


int DFS(int curr) {
	for (int i = 0; i < graph[curr].size(); ++i) {
		if (!visit[graph[curr][i]]) {
			visit[graph[curr][i]] = 1;
			duplicate[graph[curr][i]] = 1;
			return 1 + DFS(graph[curr][i]);
		}
	}
	return 0;
}



int main() {
	fast();
	cin >> T;
	while (T--) {
		cin >> N;
		init(N);
		for (int i = 0; i < N; ++i) {
			cin >> u >> v;
			graph[u].push_back(v);
		}
		int mx_id = 1000, mx = 0;
		for (int i = 1; i <= N; ++i) {
			if (duplicate[i])
				continue;
			memset(visit, 0, sizeof(visit));
			visit[i] = 1;
			tp = DFS(i);
			if (tp > mx) {
				mx = tp;
				mx_id = i;
			}
			else if (tp == mx) {
				mx = tp;
				mx_id = min(mx_id, i);
			}
		}
		cout << "Case " << kase++ << ": " << mx_id << '\n';
	}

	return 0;
	// 如果 i 在前面被做過一次那就不用再做一次了，因為前面是從某個人寄到 i
            // 一定會比直接寄到 i 還要多人
					// 如果數量相同 則輸出數字小的人

}
```
