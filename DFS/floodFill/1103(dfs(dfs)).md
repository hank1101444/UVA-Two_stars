```cpp
#include <iostream>
using namespace std;
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
int H, W, ytp, sum;
string s;
char graph[210][210];
char check[210][210];
char c;
map <char, string> mp = {
	{'0', "0000"},
	{'1', "0001"},
	{'2', "0010"},
	{'3', "0011"},
	{'4', "0100"},
	{'5', "0101"},
	{'6', "0110"},
	{'7', "0111"},
	{'8', "1000"},
	{'9', "1001"},
	{'a', "1010"},
	{'b', "1011"},
	{'c', "1100"},
	{'d', "1101"},
	{'e', "1110"},
	{'f', "1111"},
};

map <int, char> m_ans = {
	{0, 'W'},
	{1, 'A'},
	{2, 'K'},
	{3, 'J'},
	{4, 'S'},
	{5, 'D'},
};

// 0 means untraversal, 1 : background, 2 : black, 3 : white
#define Ungo 'u'
#define Black '1'
#define White '0'
int dir[4][2] = { {0,-1}, {-1,0}, {0, 1}, {1, 0} };


void dfs_bg(int x, int y) {
	if (graph[x][y] != Black) {
		check[x][y] = '1';
		for (int i = 0; i < 4; ++i) {
			int xtp = x + dir[i][0];
			int ytp = y + dir[i][1];
			// 多增加一圈 讓他把所有背景走過
			if (xtp >= 0 && ytp >= 0 && xtp <= H + 1 && ytp <= W + 1 && check[xtp][ytp] != '1') {
				dfs_bg(xtp, ytp);
			}
		}
	}
}

void dfsW(int x, int y) {
	if (graph[x][y] == White && !check[x][y] != '1') {
		check[x][y] = '1';
		for (int i = 0; i < 4; ++i) {
			int xtp = x + dir[i][0];
			int ytp = y + dir[i][1];
			if (xtp > 0 && ytp > 0 && xtp <= H && ytp <= W) {
				dfs_bg(xtp, ytp);
			}
		}
	}
}

// 看黑色裡白色數目來決定代表字
void dfsB(int x, int y) {
	if (graph[x][y] == White && check[x][y] != '1') {
		sum += 1;
		dfsW(x, y);
	}

	else if (graph[x][y] == Black && check[x][y] != '1') {
		check[x][y] = '1';
		for (int i = 0; i < 4; ++i) {
			int xtp = x + dir[i][0];
			int ytp = y + dir[i][1];
			if (xtp > 0 && ytp > 0 && xtp <= H && ytp <= W) {
				dfsB(xtp, ytp);
			}
		}
	}
}



int main() {
	int ks = 1;
	while (cin >> H >> W && (H && W)) {
		memset(graph, Ungo, sizeof(graph));
		memset(check, '0', sizeof(check));
		s = "";
		for (int i = 1; i <= H; ++i) {
			ytp = 1;
			for (int j = 1; j <= W; ++j) {
				cin >> c;
				for (int k = 0; k < 4; ++k) {
					graph[i][ytp++] = mp[c][k];
				}
			}
		}
		W *= 4;
		// detect bg
		dfs_bg(0, 0);
		// 從 (1,1 )開始當地圖因為要先跑完背景使黑色碰到裡面為白色時能計算
		for (int i = 1; i <= H; ++i) {
			for (int j = 1; j <= W; ++j) {
				if (graph[i][j] == Black && check[i][j] != '1') {
					sum = 0;
					dfsB(i, j);
					s += m_ans[sum];
				}
			}
		}
		sort(s.begin(), s.end());
		cout << "Case " << ks++ << ": " << s << '\n';
	}

	return 0;
}
```
