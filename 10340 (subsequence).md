## subsequence 意思為有序的集合

```cpp
#include <iostream>
using namespace std;
#include <string>

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		bool flag = false;
		int i = 0, j = 0;
		while (1) {
			if (s2[j] == s1[i])
				++i;
			if (s1[i] == '\0') {
				cout << "Yes" << endl;
				break;
			}
			++j;
			if (s2[j] == '\0') {
				cout << "No" << endl;
				break;
			}
		}


	}



	return 0;
}
```
