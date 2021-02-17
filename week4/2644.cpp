//촌수계산
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec[101];
int depth[101] = { 0, };
int start, target;

void bfs() {
	queue<int> q;
	q.push(start);

	while (!q.empty()){ //방문하지 않은 노드가 존재하지 않을때까지 반복
		int x = q.front();
		q.pop(); //큐의 맨앞에 있는 노드를 빼고 인접한 노드를 큐에 넣는다
		for (int i = 0; i < vec[x].size(); i++){
			int y = vec[x][i];
			if (y != start && depth[y] == 0) {//방문하지 않았던 노드라면
				q.push(y);
				depth[y] = depth[x] + 1;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cin >> start >> target;

	int m;
	cin >> m;
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	bfs();
	if (depth[target] == 0) cout << -1;
	else cout << depth[target];
}