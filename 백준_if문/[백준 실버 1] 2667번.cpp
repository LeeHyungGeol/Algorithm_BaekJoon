// dfs/bfs문제
// dfs를 이용하여 connected components를 구하는 문제
// 각각의 component들의 갯수도 함께 구하는 문제이다.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<vector<int>> graph;
vector<vector<bool>> visited;
vector<int> nodes;

int dfsAll();
int dfs(int x, int y);

int main() {
	cin >> N;

	graph.resize(N, vector<int>(N));
	visited.resize(N, vector<bool>(N, false));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%1d", &graph[i][j]);
		}
	}

	int components = dfsAll();

	cout << components << '\n';

	sort(nodes.begin(), nodes.end());

	for (int node : nodes) {
		cout << node << '\n';
	}

	return 0;
}

int dfsAll() {
	int components = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j] && graph[i][j] == 1) {
				int node = dfs(i, j);
				++components;
				nodes.push_back(node);
			}
		}
	}

	return components;
}

int dfs(int x, int y) {
	visited[x][y] = true;
	int node = 1;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			if (!visited[nx][ny] && graph[nx][ny] == 1) {
				node += dfs(nx, ny);
			}
		}
	}

	return node;
}