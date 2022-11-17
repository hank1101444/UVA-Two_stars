```cpp
#include <iostream>
using namespace std;
#include <set> 
#include <unordered_set>
#include <list>
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	unordered_set <int> s;
	list <int> l;
	int n, a, total;
	cin >> n;
	while (n--) {
		total = 0;
		int t;
		s.clear();
		l.clear();
		cin >> t;
		for (int i = 0; i < t; ++i) {
			cin >> a;
			// 重複時先將重複的刪除 以及之前的 因為前面已經紀錄 最大了 最後再插入
			if (s.count(a)) {
				bool check = true;
				int tp = l.size();
				// 我希望他check size 次數 所以要用tp 去暫存不可以用l.size因為它會變動 
				// wrong : j < l.size()
				for (int j = 0;j < tp && check; ++j) {
					if (*l.begin() == a) 
						check = false;
					
					s.erase(*l.begin());
					l.pop_front();
				}
				
			}
			// wrong
			// unordered_set 沒有排序 所以 begin 可能會亂掉 用一個vector 來記
			/*while (s.count(a))
				s.erase(s.begin());*/
 			l.push_back(a);
			s.insert(a);
			total = max(total,int(l.size()));
		}
		/*for (auto it = s.begin(); it != s.end(); ++it) {
			cout << *it;
		}*/
		cout << total << endl;
	}
	return 0;
}

/*
1
12
7
4
0
9
4
8
8
2
4
5
5
1
*/
// ans : 4
```
