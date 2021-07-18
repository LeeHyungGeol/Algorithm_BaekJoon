// bfs, dfs 문제
// graph 탐색을 물어보는 기본 문제

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int cur);
void bfs(int cur);

int main() {
	cin >> N >> M >> V;

	graph.resize(N+1, vector<int>());
	visited.resize(N+1, false);

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i < graph.size(); ++i) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V);
	cout << '\n';
	bfs(V);

	return 0;
}

void dfs(int cur) {
	visited[cur] = true;

	cout << cur << ' ';

	for (int next : graph[cur]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}

void bfs(int cur) {
	visited.assign(N + 1, false);
	queue<int> q;
	q.push(cur);
	visited[cur] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now << ' ';

		for (int next : graph[now]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}

	cout << '\n';

	return;
}