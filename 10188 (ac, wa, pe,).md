## 可以把所有string 加在一起比較
## 記得\n要考慮進去
## 如果輸入兩筆都是空字串 則最後字串為 "\n"

```cpp
#include <iostream>
using namespace std;
#include <string>

int sol(int n_ans) {
	//string dpans[101];
	//string dpsol[101];
	string ans, sol, tmp;
	int t = 0, n_sol;

	// getline 不會把\n 讀近來所以要自己加
	for (int i = 0; i < n_ans; ++i) {
		getline(cin, tmp);
		if (i) {				// modify
			ans += '\n';
			ans += tmp;
		}
		else
			ans = tmp;
	}
	cin >> n_sol;
	cin.ignore();
	t = 0;
	for (int i = 0; i < n_sol; ++i) {
		getline(cin, tmp);
		if (i) {				// modify
			sol += '\n';
			sol += tmp;
		}
		else
			sol = tmp;
	}
	// ac
	if (ans == sol)
		return 1;

	// pre err
	for (int i = 0; i < ans.size();) {
		if (ans[i] < '0' || ans[i] > '9')
			ans.erase(i, 1);
		else
			++i;
	}
	for (int i = 0; i < sol.size();) {
		if (sol[i] < '0' || sol[i] > '9')
			sol.erase(i, 1);
		else
			++i;
	}

	if (ans == sol)
		return 3;

	return 2;

}


int main() {
	int tc, t = 1;
	string p[4] = { "", "Accepted", "Wrong Answer", "Presentation Error" };
	while (cin >> tc && tc != 0) {
		cin.ignore();
		cout << "Run #" << t << ": " << p[sol(tc)] << endl;
		++t;
	}

	return 0;
}
```
