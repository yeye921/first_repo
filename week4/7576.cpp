//토마토
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int a[1001][1001];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int d[1001][1001]; // 토마토 익은 날짜

int main() {
	int m, n; // m 가로(열), n 세로(행)
	cin >> m >> n;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			d[i][j] = -1; // 아직 방문하지 않은 토마토
			if (a[i][j] == 1) {
				q.push(make_pair(i, j)); // 익은 토마토가 있으면 큐에 넣기
				d[i][j] = 0; //원래 익은 친구들이니까 0
			}
		}
	}
	while (!q.empty()) {
	int x = q.front().first; // 첫번째로 들어간 익은 토마토 x 좌표
	int y = q.front().second; // 첫번째로 들어간 익은 토마토의 y 좌표
	q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] == 0 && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1; // 날짜 증가
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result = max(result, d[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && d[i][j] == -1) { // 안익고 방문된적 없으면 -1
				result = -1;
			}
		}
	}
	cout << result;
}