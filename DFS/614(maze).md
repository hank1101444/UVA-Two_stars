```cpp
#include <iostream>
using namespace std;
#include <cstring>
#include <iomanip>
// the order is WNES
int direction[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int row, col, x, y, fx, fy, tp;
int graph[15][15], record[15][15];
bool flag = 0;

bool isBoard(int _x, int _y, int dir) {
	if (_x + direction[dir][0] < 1 || _x + direction[dir][0] > row)
		return true;
	if (_y + direction[dir][1] < 1 || _y + direction[dir][1] > col)
		return true;
	return false;
}

void dfs(int cur_x, int cur_y) {
	int nx_x, nx_y;
	if (cur_x == fx && cur_y == fy) {
		flag = 1;
		return;
	}
	//W
	// 先check 邊界 注意是帶當前點進入
	if (!isBoard(cur_x, cur_y, 0)) {
		nx_x = cur_x + direction[0][0];
		nx_y = cur_y + direction[0][1];
		// check 是否有牆
		// 檢查 nx 的 E 有沒有牆 沒牆才能進去
		// error 要記得檢查下一步是不是已經走過
		if (record[nx_x][nx_y] == 0 && (graph[nx_x][nx_y] == 0 || graph[nx_x][nx_y] == 2)) {
			// 會是上一個狀態+1
			record[nx_x][nx_y] = record[cur_x][cur_y] + 1;
			dfs(nx_x, nx_y);
			// 如果找到了就return 不需要再去其他方位
			if (flag)
				return;
			// 回頭後如果flag 沒變true 就代表為死路就要標記為-1
			record[nx_x][nx_y] = -1;
		}
	}
	//N
	if (!isBoard(cur_x, cur_y, 1)) {
		nx_x = cur_x + direction[1][0];
		nx_y = cur_y + direction[1][1];
		if (record[nx_x][nx_y] == 0 && (graph[nx_x][nx_y] == 0 || graph[nx_x][nx_y] == 1)) {
			record[nx_x][nx_y] = record[cur_x][cur_y] + 1;
			dfs(nx_x, nx_y);
			if (flag)
				return;
			record[nx_x][nx_y] = -1;
		}
	}
	//E (ES用當前node 來檢查有沒有牆)
	if (!isBoard(cur_x, cur_y, 2)) {
		nx_x = cur_x + direction[2][0];
		nx_y = cur_y + direction[2][1];
		if (record[nx_x][nx_y] == 0 && (graph[cur_x][cur_y] == 0 || graph[cur_x][cur_y] == 2)) {
			record[nx_x][nx_y] = record[cur_x][cur_y] + 1;
			dfs(nx_x, nx_y);
			if (flag)
				return;
			record[nx_x][nx_y] = -1;
		}
	}
	//S (ES用當前node 來檢查有沒有牆)
	if (!isBoard(cur_x, cur_y, 3)) {
		nx_x = cur_x + direction[3][0];
		nx_y = cur_y + direction[3][1];
		if (record[nx_x][nx_y] == 0 && (graph[cur_x][cur_y] == 0 || graph[cur_x][cur_y] == 1 )) {
			record[nx_x][nx_y] = record[cur_x][cur_y] + 1;
			dfs(nx_x, nx_y);
			if (flag)
				return;
			record[nx_x][nx_y] = -1;
		}
	}
}
int south_wall[15];
void row_wall() {
	cout << '+';
	for (int i = 1; i <= col; ++i) {
		if (south_wall[i] == 0)
			cout << "   +";
		else
			cout << "---+";
	}
	cout << '\n';
}

void output() {
	// 最前面要設成有牆
	for (int i = 1; i <= col; ++i) {
		south_wall[i] = 1;
	}
	row_wall();
	// error 記得檢查是不是沒走到終點 因為起點也要設為-1
	if (!flag)
		record[x][y] = -1;
	for (int i = 1; i <= row; ++i) {
		// initiall south_wall
		for (int j = 1; j <= col; ++j) {
			south_wall[j] = 0;
		}
		cout << '|';
		for (int j = 1; j <= col; ++j) {
			if (record[i][j] > 0)
				cout << setw(3) << record[i][j];
			else if (record[i][j] == -1)
				cout << "???";
			else if (record[i][j] == 0)
				cout << "   ";
			// E 有牆
			if (graph[i][j] == 1 || graph[i][j] == 3|| j == col)
				cout << '|';
			else {
				// 最後一個不能輸出space
				if(j<col)
					cout << ' ';
			}
			// S有牆
			if (graph[i][j] == 2 || graph[i][j] == 3)
				south_wall[j] = 1;
		}
		cout << "\n";
		if (i == row) {
			// 最後面要設成有牆
			for (int i = 1; i <= col; ++i) {
				south_wall[i] = 1;
			}
		}
		row_wall();
	}
}

int main() {
	int n = 1;
	while (cin >> row >> col >> x >> y >> fx >> fy && row) {
		cout << "Maze " << n++ << "\n\n";
		memset(graph, 0, sizeof(graph));
		memset(record, 0, sizeof(record));
		for (int i = 1; i <= row; ++i) {
			for (int j = 1; j <= col; ++j) {
				cin >> tp;
				// graph 用來記 wall 狀態
				// 0: ES都沒牆 1: E有牆 2: S有牆 3: ES都有牆
				graph[i][j] = tp;
				// record 用來記 走的狀態
			}
		}
		flag = 0;
		record[x][y] = 1;
		dfs(x, y);
		output();
		cout << "\n\n";
	}

	return 0;
}

```
