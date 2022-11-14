```cpp
#include<iostream>
using namespace std;
#include <vector>
#include<set>
#include <cmath>
int main() {

	int n, v;
	cin >> n;
	multiset <int> green{}, blue{};
	multiset <int>::iterator itg, itb;
	vector <int> result;
	while (n--) {
		green.clear();
		blue.clear();
		int g, b, people;
		cin >> people >> g >> b;
		while (g--) {
			cin >> v;
			green.insert(v);
		}
		while (b--) {
			cin >> v;
			blue.insert(v);
		}
		while (!green.empty() && !blue.empty()) {
			for (int i = 0; i < people; ++i) {
				if (green.empty() || blue.empty())
					break;
				result.push_back(*green.rbegin() - *blue.rbegin());
				green.erase(--green.end());		//error
				blue.erase(--blue.end());
			}
			for (int i = 0; i < result.size(); ++i) {
				if (result[i] > 0)
					green.insert(result[i]);
				else if (result[i] < 0)			// modify 0 表沒有人贏
					blue.insert(abs(result[i]));
			}
			result.clear();
		}
		if (green.empty() && blue.empty())
			cout << "green and blue died\n";
		else if (green.empty()) {
			cout << "blue wins\n";
			for (multiset <int>::reverse_iterator it = blue.rbegin(); it != blue.rend(); ++it) {
				cout << *it << '\n';
			}
		}

		else {
			cout << "green wins\n";
			for (multiset <int>::reverse_iterator it = green.rbegin(); it != green.rend(); ++it) {
				cout << *it << '\n';
			}
		}
		if(n)
			cout << '\n';
	}


	return 0;
}
```
