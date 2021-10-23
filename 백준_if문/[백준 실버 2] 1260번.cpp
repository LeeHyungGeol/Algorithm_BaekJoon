#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> Graph;
vector<bool> Visited;

void dfs(int cur);
void bfs(int cur);

int main() {
	cin >> N >> M >> V;

	Graph.resize(N+1);

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}

	for (int i = 1; i <= N; ++i) sort(Graph[i].begin(), Graph[i].end());

	Visited.assign(N + 1, false);
	dfs(V);
	cout << '\n';
	Visited.assign(N + 1, false);
	bfs(V);

	return 0;
}

void dfs(int cur) {
	Visited[cur] = true;
	cout << cur << ' ';

	for (int next : Graph[cur]) {
		if (Visited[next]) continue;
		dfs(next);
	}
}

void bfs(int cur) {
	queue<int> q;

	q.push(cur);
	Visited[cur] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << ' ';

		for (int next : Graph[cur]) {
			if (Visited[next]) continue;
			Visited[next] = true;
			q.push(next);
		}
	}
}

