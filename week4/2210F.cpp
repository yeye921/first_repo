// 숫자판 점프
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int arr[5][5];
vector<int> vec;
map<string, bool> m;
int ans;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void DFS(int y, int x, int cur)
{
	if (cur == 5)
	{
		string str;
		for (int i = 0; i < 6; i++)
		{
			str += vec[i] + '0';
		}
		if (!m[str])
		{
			m[str] = true;
			ans++;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int newy = y + dy[i];
		int newx = x + dx[i];

		if (newy >= 0 && newy < 5 && newx >= 0 && newx < 5)
		{
			vec.push_back(arr[newy][newx]);
			DFS(newy, newx, cur + 1);
			vec.pop_back();
		}
	}
}


int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			vec.push_back(arr[i][j]);
			DFS(i,j,0);
			vec.pop_back();
		}
	}
	cout << ans << endl;
}