```cpp
#include <iostream>
using namespace std;
#include <set>
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	multiset<int> ml;
	long long int n, tp, total;
	while (cin >> n && n != 0) {
		total = 0;
		ml.clear();
		while(n--) {
			int a;
			cin >> a;
			for (int i = 0; i < a; ++i) {
				cin >> tp;
				ml.insert(tp);
			}
			total += (*ml.rbegin() - *ml.begin());
			ml.erase(--ml.end());
			ml.erase(ml.begin());
		}
		cout << total << '\n';
	}
	return 0;
}
```
