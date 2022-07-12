```cpp
#include <iostream>
using namespace std;
#include <cmath>

char dp[10002];
int sz;
bool solve() {
	int base = 1;
	int num = 0;
	for (int i = sz - 1; i >= 0; --i) {
		// 把有可能被130171約掉的全部mod 會變成只有一堆 130171的 remainder 相加
		num += base * (dp[i] - '0');
		base *= 2;
		// base 有可能超過所以也要先mod
		base %= 131071;
		// 這些remainder 相加後要再 mod 一次才是真正的remainder
		num %= 131071;
	}
	return num;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	sz = 0;
	char c;
	while (cin >> c) {
		if (c == '#') {
			if (solve())
				cout << "NO\n";
			else
				cout << "YES\n";
			sz = 0;
		}
		else {
			++sz;
			dp[sz - 1] = c;
		}
	}
	return 0;
}

```
