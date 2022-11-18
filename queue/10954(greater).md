
## ans 是將每次結果加起來
```cpp
#include <iostream>
using namespace std;
#include<queue>
#include <vector>
int main() {
	int n, tp, ans;
	//priority_queue <int,vector <int>,  greater<int>> pq;
	while (cin >> n && n!=0) {
		priority_queue <int, vector <int>, greater<int>> pq;
		ans = 0;
		for (int i = 0; i < n; ++i) {
			int val;
			cin >> val;
			pq.push(val);
		}
		while (pq.size() > 1) {
			tp = pq.top(), pq.pop();
			tp += pq.top(), pq.pop();
			ans += tp;
			pq.push(tp);
		}
		// 可以將 priority_queue 宣告在迴圈裡 這樣就可以不用江最後刪除
		//pq.pop();
		cout << ans << endl;
	}


	return 0;
}
```
