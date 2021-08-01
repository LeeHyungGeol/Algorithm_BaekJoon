// bfs문제
// 간선의 가중치가 모두 같을 때 최단경로 탐색 알고리즘

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M, X, Y;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<vector<int>> Graph;
vector<vector<int>> Dist;
vector<vector<bool>> Visited;

void bfs(int startX, int startY);

int main() {
	cin >> N >> M;

	Graph.resize(N, vector<int>(M, 0));
	Dist.resize(N, vector<int>(M, 0));
	Visited.resize(N, vector<bool>(M, false));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> Graph[i][j];
			
			if (Graph[i][j] == 2) {
				X = i;
				Y = j;
			}
		}
	}

	bfs(X, Y);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << Dist[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

void bfs(int startX, int startY) {
	queue<pii> q;
	q.push({ startX, startY });

	Visited[startX][startY] = true;
	Dist[startX][startY] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (!Visited[nx][ny] && Graph[nx][ny] == 1) {
					Visited[nx][ny] = true;
					Dist[nx][ny] = Dist[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (Graph[i][j] == 1 && !Visited[i][j]) {
				Dist[i][j] = -1;
			}
		}
	}

	return;
}