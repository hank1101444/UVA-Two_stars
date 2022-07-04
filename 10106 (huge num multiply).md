#include <iostream>
using namespace std;
#include <string>
#include <cstring>
string sa, sb;
int a[250], b[250], c[500], cs;

int main() {
	while (cin >> sa >> sb) {
		if (sa == "0" || sb == "0") {
			cout << 0 << endl;
			continue;
		}
			
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 0; i < sa.size(); ++i)
			a[i] = sa[sa.size() - 1 - i] - '0' + 0;
		for (int i = 0; i < sb.size(); ++i)
			b[i] = sb[sb.size() - 1 - i] - '0' + 0;
		memset(c, 0, sizeof(c));
		for (int i = 0; i < sa.size(); ++i) {
			for (int j = 0; j < sb.size(); ++j)
				c[i + j] += a[i] * b[j];
		}
		cs = sa.size() + sb.size();
		for (int i = 0; i < cs; ++i) {
			if (c[i] > 9) {
				c[i + 1] += c[i] / 10;
				c[i] %= 10;
			}
		}
		if (!c[cs - 1])
			--cs;
		for (int i = cs - 1; i >= 0; --i)
			cout << c[i];
		cout << endl;
	}
	return 0;
}
