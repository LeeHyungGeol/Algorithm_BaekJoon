// dfs, bfs문제
// connected components를 구하는 문제

#include <iostream>
#include <vector>

using namespace std;

int T, N, M, K;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<vector<int>> graph;
vector<vector<bool>> visited;

int dfsAll();
int dfs(int x, int y);

int main() {
	cin >> T;
	
	for (int t = 0; t < T; ++t) {
		cin >> M >> N >> K;
		
		graph.clear();
		visited.clear();
		graph.resize(M, vector<int>(N, 0));
		visited.resize(M, vector<bool>(N, false));

		for (int i = 0; i < K; ++i) {
			int a, b;
			cin >> a >> b;
			graph[a][b] = 1;
		}

		cout << dfsAll() << '\n';
	}

	return 0;
}

int dfsAll() {
	int components = 0;

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j] && graph[i][j] == 1) {
				dfs(i, j);
				++components;
			}
		}
	}

	return components;
}

int dfs(int x, int y) {
	int nodes = 1;
	visited[x][y] = true;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < M && 0 <= ny && ny < N) {
			if (!visited[nx][ny] && graph[nx][ny] == 1) {
				nodes += dfs(nx, ny);
			}
		}
	}

	return nodes;
}