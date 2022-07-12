## 僅適用除數非大數時， 使用一般除法方法

```cpp
//#include <iostream>
//using namespace std;
//#include <cmath>
//#include <iomanip>
//int main() {
//	int n,p, t;
//	double d;
//	cin >> t;
//	while (t--) {
//		cin >> p >> d >> n;   
//		double ans = pow((1 - d), n - 1) * d;
//		cout << setprecision(4) << ans <<endl;
//	}
//
//	return 0;
//}
//

#include <iostream>
using namespace std;
#include <cstring>
int a[25], b[25], d[25];
char c[25];
int n, f;
int as,ds;

void solve() {
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(d, 0, sizeof(d));
	as = 25;
	ds = 25;
	while (n--) {
		cin >> c;
		for (int i = strlen(c) - 1, j = 0; i >= 0;)
			b[i--] = c[j++] - '0';

		for (int i = 0; i < strlen(c); ++i)
			a[i] += b[i];

		// just carry all 
		for (int i = 0; i < 25; ++i) {
			if (a[i] >= 10) {
				a[i + 1] += a[i] / 10;
				a[i] %= 10;
			}
		}
	}
	while (!a[as - 1] && as)
		--as;
	memcpy(d, a, sizeof(int) * as);

	// only use on divisor not big num
	int r = 0;		//remainder
	for (int i = as - 1; i >= 0; --i) {
		r = r * 10 + a[i];
		d[i] = r / f;
		r %= f;
	}
	while (!d[ds - 1] && ds)
		--ds;

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	while (cin >> n >> f) {
		if (!n && !f)
			break;
		solve();
		cout << "Bill #" << t++ << " costs ";
		for (int i = as - 1; i >= 0; --i)
			cout << a[i];
		if (!as)
			cout << 0;
		cout << ": each friend should pay ";
		for (int i = ds - 1; i >= 0; --i)
			cout << d[i];
		if (!ds)
			cout << 0;
		cout << "\n\n";
	}


	return 0;
}



```
