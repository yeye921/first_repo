//효율적인 해킹
#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 10001

int N, M;
vector <int> vec[MAX];
vector <int> check;
bool visit[MAX];
int cnt;

void DFS(int node_num) {
	visit[node_num] = true;

	for (int i = 0; i < vec[node_num].size(); i++) { //인접한 노드를 방문
		int node_nextNum = vec[node_num][i];

		if (!visit[node_nextNum]) {
			cnt++;
			DFS(node_nextNum);
		}
	}
}
int main() {

    ios::sync_with_stdio(false);
	cin.tie(0); 
    cout.tie(0);
	
    cin >> N >> M;  //컴퓨터 개수, 신뢰하는 관계 개수 입력받음

	for (int i = 0; i < M; i++) {
		int start, end;      
		cin >> start >> end;   //start는 end를 신뢰함
		vec[end].push_back(start);  //신뢰받는 노드 끝에 신뢰하는 노드를 추가해줌
	}
	
	int node_count = 0;

	for (int i = 1; i <= N; i++) {
		cnt = 0;
		
		DFS(i);
		if (node_count == cnt)  //최대 탐색이 되는 노드를 check벡터에 push함
			check.push_back(i); 

		else if (node_count < cnt) { //노드 갯수가 더 클경우 
			node_count = cnt;
			check.clear();
			check.push_back(i);
		}
	}
	
	sort(check.begin(), check.end()); //오름차순으로 정렬
	for (int i = 0; i < check.size(); i++)
		cout << check[i] << " ";
	
	return 0;
}