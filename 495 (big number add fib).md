```cpp
#include <iostream>
using namespace std;
#include <cstring>

int f[5001][1500], d[5001];

int main() {
	// fib f[i] < f[i-1] * 2 so if i = 5000 f[i] must < 2^5000 = 10^1500 so we need 1500 to store
	memset(f, 0, sizeof(f));
	memset(d, 0, sizeof(d));
	f[1][0] = 1;
	d[0] = 1;
	d[1] = 1;
	for (int i = 2; i < 5001; ++i) {
		for (int j = 0; j < 1500; ++j) {
			f[i][j] = f[i - 1][j] + f[i - 2][j] + f[i][j]; // +f[i][j] because you may have carry before
			if (f[i][j] >= 10) {
				f[i][j + 1] += f[i][j] / 10;
				f[i][j] %= 10;
			}
		}
		d[i] = d[i - 1];
		if (f[i][d[i]])		// the addition carry have only one
			++d[i];
	}

	int n;
	while (cin >> n) {
		cout << "The Fibonacci number for " << n << " is ";
		for (int i = d[n]-1; i >= 0; --i) {
			cout << f[n][i];
		}
		cout << endl;
	}

	return 0;
}
```
