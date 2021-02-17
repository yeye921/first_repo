// 유기농 배추
#include <iostream>
#include <string.h>
using namespace std;

enum { NONE, CABBAGE, VISITED }; // 배추 있/없/방문 표시

int T, M, N, K;
int Map[50][50];

void dfs(int x, int y)
{
    static int dy[] = { -1, 1, 0, 0 };
    static int dx[] = { 0, 0, -1, 1 };

    Map[y][x] = VISITED;  // 방문 했음을 표시

    for (int i = 0; i < 4; ++i)   // 인접한 4곳을 확인
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;
       
        if (Map[ny][nx] == CABBAGE)  // 주변에 배추가 있다면 탐색
            dfs(nx, ny);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   cin >> T; //테스트케이스 개수
    while (T--)
    {
     cin >> M >> N >> K;
        for (int k = 0; k < K; ++k)
        {
            int x, y;
            cin >> x >> y;  //배추위치 입력받음
            Map[y][x] = CABBAGE;  //배추있다고 표시함
        }
        
        int result = 0;
        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < M; ++x)
            {
                if (Map[y][x] == CABBAGE) // 배추가 있다면
                {
                    dfs(x, y);            // 탐색
                    ++result;  // 탐색 횟수 == 필요한 지렁이 수
                }
            }
        }
        cout << result << '\n';
    }
}


