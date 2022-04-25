```cpp
#include <iostream>
using namespace std;
#include <string>
#include <vector>
string s;
int check(vector <char> v) {
	int j = 0;
	int count = 0;
	while (1) {
		//for (int j = 0; j < s.size();) {
			for (int i = 0; i < v.size(); i++, j++) {
				if (j == s.size())
					return count;
				if (v[i] != s[j]) {
					return -1;
				}
			}
			count++;
		//}
	}
}

int main() {
	
	vector <char> v;
	while (cin >> s) {
		if (s == ".")
			break;
		int ans = 0;
		v.clear();
		for (int i = 0; i < s.size(); i++) {
			v.push_back(s[i]);
			ans = check(v);
			if (ans != -1)
				break;
		}
		cout << ans << endl;
	}


	return 0;
}
```
