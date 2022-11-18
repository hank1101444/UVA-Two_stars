```cpp
#include <iostream>
using namespace std;
#include <stack>
#include <queue>
int main() {
	int n;
	while (cin >> n) {
		bool bs = true, bq = true, bpq = true;
		stack <int> s;
		queue <int> q;
		priority_queue <int> pq;
		int command;
		while (n--) {
			cin >> command;
			if (command == 1) {
				int tp;
				cin >> tp;
				s.push(tp);
				q.push(tp);
				pq.push(tp);
			}
			else {
				int val;
				cin >> val;
				// 這題要防呆
				if (bs) {
					if (!s.empty() && s.top() == val)
						s.pop();
					else
						bs = false;
				}
				if (bq) {
					if (!q.empty() && q.front() == val)
						q.pop();
					else
						bq = false;
				}
				
				if (bpq) {
					if (!pq.empty() && pq.top() == val)
						pq.pop();
					else
						bpq = false;
				}
			}
		}
		// 先看有沒有兩個以上相同的
		if ((bs && bq) || (bs && bpq) || (bq && bpq))cout << "not sure\n";
		else if (bs)cout << "stack\n";
		else if (bq)cout << "queue\n";
		else if (bpq)cout << "priority queue\n";
		else cout << "impossible\n";

	}


	return 0;
}
```
