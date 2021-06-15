// 다익스트라 최단 경로 문제
// (1, 1) 부터 (N, M) 까지 이동하는데 걸리는 최단 경로이며, 
// 그때 까지 부순 벽의 최소 개수를 구하는 문제
// 이 문제의 핵심은 최단 경로이므로 한번 간 길은 다시 되돌아가지 않는 것에 있다.
// 그러므로 다익스트라 최단 경로 알고리즘을 사용할 수 있다.
 
// 주의해야할 점
// N, M이 각각 행, 렬이 아니라 렬, 행이라는 점

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)

#define INF 1e9

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int N, M;
int graph[100][100] = { 0, };
int d[100][100] = { 0, };
bool visited[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dijkstra(int x, int y);

int main() {
	// N: 세로크기, 행
	// M: 가로크기, 렬
	cin >> M >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%1d", &graph[i][j]);
			//d[i][j] = INF;
		}
	}

	for (int i = 0; i < N; ++i) {
		fill(d[i], d[i] + M, INF);
	}

	dijkstra(0, 0);

	cout << d[N - 1][M - 1] << '\n';
	
	return 0;
}

void dijkstra(int x, int y) {
	priority_queue<piii> pq;

	pq.push({ 0, { x, y } });
	d[x][y] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;

		pq.pop();

		// 현재 노드가 이미 처리된 적이 있는 노드라면 무시
		if (d[x][y] < dist) {
			continue;
		}

		/*
		if(visited[x][y]) {
			continue;
		}

		visited[x][y] = true;
		*/

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (dist + graph[nx][ny] < d[nx][ny]) {
					d[nx][ny] = dist + graph[nx][ny];
					pq.push({ -d[nx][ny], {nx, ny} });
				}
			}
		}
	}

	return;
}