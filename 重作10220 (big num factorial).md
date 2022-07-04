## 如果知道範圍 其實可以不用特地算出size 直接多算一點沒差
### 如果想知道大小可這樣寫
```cpp
while (a[size - 1] > 10) {
		a[size] = a[size - 1] / 10;
		a[size - 1] %= 10;
		++as;
	}
```
## 遇到會利用到前面結果的運算 可以考慮先算完全部可能 ex : 階乘
```cpp
#include <iostream>
#include <cstring>
using namespace std;

int s[1001]; // 0 ~1000
int a[3000]; // big (4 + 3*999)
int n;
//int as = 1;  no need to calculize size just 3000
int main() {
	memset(s, 0, sizeof(s));
	memset(a, 0, sizeof(a));
	a[0] = 1;
	s[0] = 1;
	for (int i = 1; i < 1001; ++i) {
		for (int j = 0; j < 3000; ++j) 
			a[j] *= i;
		for (int j = 0; j <3000; ++j) {
			if (a[j] > 9) {
				a[j + 1] += a[j] / 10;
				a[j] %= 10;
			}
			s[i] += a[j];
		}
			
	}
	while (cin >> n)
		cout << s[n] << endl;

	return 0;
}
```
