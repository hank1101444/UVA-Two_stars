```cpp
#include <iostream>
using namespace std;
#include <cstring>
int a[1000002];
int main() {
	int n;
	cin >> n;
	while (n--) {
		memset(a, 0, sizeof(a));
		int sa, ia, ib;
		cin >> sa;
		for (int i = sa - 1; i >= 0; --i) {
			cin >> ia >> ib;
			a[i] = ia + ib;
		}
		for (int i = 0; i <= sa; ++i) {
			if (a[i] >= 10) {
				a[i + 1] += a[i] / 10;
				a[i] %= 10;
			}
		}
		if (a[sa])
			++sa;
		for (int i = sa - 1; i >= 0; --i) {
			cout << a[i];
		}
		if (n)
			cout << endl;
		cout << endl;
	}
	return 0;
}
```
