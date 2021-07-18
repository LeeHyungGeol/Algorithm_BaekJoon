// BFS 문제 
// 간선의 비용(weight)이 모두 같을 때, 최단 거리를 탐색하기 위해 사용할 수 있는 알고리즘
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<vector<int>> graph;
vector<vector<int>> dist;

void bfs(int x, int y);

int main() {
	cin >> N >> M;

	graph.resize(N, vector<int>(M));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%1d", &graph[i][j]);
		}
	}
	
	bfs(0, 0);

	cout << dist[N - 1][M - 1] << '\n';

	return 0;
}

void bfs(int x, int y) {
	dist.resize(N, vector<int>(M, -1));
	queue<pii> q;
	q.push({ x,y });

	dist[x][y] = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M && graph[nx][ny] == 1) {
				if (dist[nx][ny] >= 0) {
					continue;
				}

				dist[nx][ny] = dist[cx][cy] + 1;
				q.push({ nx, ny });
			}
		}
	}

	return;
}