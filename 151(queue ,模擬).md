# queue使用時機: 想刪除某些資料 , 其他沒刪的可以重新排隊, 順序不變
## 本題要讓13為最後一筆資料(最後一個斷電)
```cpp
#include <iostream>
using namespace std;
#include <queue>

bool check(int number, int dif)
{
	queue<int> q;
	for (int i = 1; i <= number; i++)
		q.push(i);
	int flag = 0;
	// delete 1 first
	q.pop();
	while (q.size() != 1)
	{
		int temp = q.front();
		flag++;
		q.pop();
		if (flag == dif)
		{
			if (temp == 13)
				break;
			flag = 0;
		}
		else
			q.push(temp);
	}
	if (q.front() == 13 && q.size() == 1)
		return true;
	return false;

}


int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		for (int i = 1;; i++)
		{
			if (check(n, i))
			{
				cout << i << endl;
				break;
			}
			
		}
	}

	return 0;
}
```
