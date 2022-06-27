```cpp
#include <iostream>
using namespace std;
#include <map>
#include <string>
int main() {
	map <string, int> m;
	map <string, int> ::iterator mit;
	int n1, n2;
	cin >> n1 >> n2;
	string s;
	while (n1--) {
		int a;
		cin >> s >> a;
		m[s] = a;
	}
	while (n2--) {
		int _m = 0;
		while (cin >> s) {
			if (s == ".")
				break;
			mit = m.find(s);
			if (mit != m.end()) {
				_m += mit->second;
			}
		}
		cout << _m << endl;
	}

	return 0;
}
```
