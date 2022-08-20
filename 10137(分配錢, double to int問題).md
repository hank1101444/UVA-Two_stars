# WA 轉移量可以只考慮付少的 可是本題有考慮多付0.01 的問題
```cpp
#include <iostream>
using namespace std;
#include <cmath>
#include <algorithm>
#include <cstring>
int cost[1001];

bool cmp(int a, int b) { return a < b; }

int main() {
	memset(cost, 0, sizeof(cost));
	int n;
	double d;
	while (cin >> n && n != 0) {
		int ans = 0, avg = 0, rem = 0;
		for (int i = 0; i < n; ++i) {
			cin >> d;
			cost[i] = d * 100;
			avg += cost[i];
		}
		rem = avg % n;
		avg /= n;
		sort(cost, cost + n, cmp);
		for (int i = 0; i < n; ++i) {
			if (cost[i] < avg) 
				ans +=  avg - cost[i];
		}
		ans -= rem;
		printf("$%.2lf\n", ans / 100.0);
	}

	return 0;
}
```

# AC 要改double 因為 double to int 會有問題
```cpp
#include <iostream>
using namespace std;
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
double cost[1001];

bool cmp(double a, double b) { return a > b; }

int main() {
	memset(cost, 0, sizeof(cost));
	int n;
	double d;
	while (cin >> n && n != 0) {
		double ans = 0;
		int avg = 0, rem = 0;
		for (int i = 0; i < n; ++i) {
			// 278.78
			cin >> d;
			cost[i] = d* 100;
			avg += cost[i];
		}
		rem = avg % n;
		avg /= n;
		sort(cost, cost + n, cmp);
		// 出錢多的人多負擔一分錢(並非所有大於平均的都要負擔只需要rem 人)
		for (int i = 0; i < rem; ++i) 
			ans += abs(cost[i] - (avg + 1));
		for (int i = rem; i < n; ++i) 
			ans += abs(cost[i] - avg);
		// 因為現在算了出錢多的 也算了出少的 錢多的轉移量 = 錢少的轉移量 所以要/2
		printf("$%.2lf\n", ans / 200.0);
	}
	return 0;
}
```
