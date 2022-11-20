```cpp
#include <iostream>
using namespace std;
#include <string>
#include <queue>
class datas {
public:
	int Q, P, next;
};
// 不能寫成 member function
bool operator < (const datas& a, const datas& b) {
	// return true 代表要交換
	if (a.next == b.next)
		return a.Q > b.Q;
	// 直觀 false 不用交換
	// 小于号重载成大于号，则与默认大根堆相反，变成小根堆
	return a.next > b.next;
}


int main() {
	string s;
	datas data;
	// how about multiset??
	priority_queue <datas> pq;
	while (cin >> s && s != "#") {
		cin >> data.Q >> data.P;
		data.next = data.P;
		pq.push(data);
	}
	int n;
	while (cin >> n) {
		while (n--) {
			datas tp = pq.top();
			pq.pop();
			tp.next += tp.P;
			cout << tp.Q << endl;
			pq.push(tp);
		}
	}

	return 0;
}
```
