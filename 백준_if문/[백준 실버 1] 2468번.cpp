// dfs,bfs문제
// dfs를 이용한 connected components를 구하는 문제
// 매 높이마다 connected components의 갯수를 구하여, 최대일 때를 답으로 구한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer = 1, maxHeight;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<vector<int>> graph;
vector<vector<bool>> visited;

void dfsByHeights();
int dfsAll(int h);
void dfs(int x, int y, int h);

int main() {
	cin >> N;

	graph.resize(N, vector<int>(N));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> graph[i][j];
			maxHeight = max(maxHeight, graph[i][j]);
		}
	}

	dfsByHeights();

	cout << answer << '\n';

	return 0;
}

void dfsByHeights() {
	for (int h = 1; h <= maxHeight; ++h) {
		visited.assign(N, vector<bool>(N, false));
	
		int components = dfsAll(h);

		answer = max(answer, components);
	}

	return;
}

int dfsAll(int h) {
	int components = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j] && graph[i][j] > h) {
				dfs(i, j, h);
				++components;
			}
		}
	}

	return components;
}

void dfs(int x, int y, int h) {
	visited[x][y] = true;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			if (!visited[nx][ny] && graph[nx][ny] > h) {
				dfs(nx, ny, h);
			}
		}
	}

	return;
}