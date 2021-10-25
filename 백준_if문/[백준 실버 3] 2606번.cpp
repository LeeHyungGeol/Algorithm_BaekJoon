#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<bool> Visited;
vector<vector<int>> Graph;

int dfs(int cur);

int main() {
	cin >> N >> M;

	Graph.resize(N + 1);

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}

	Visited.resize(N + 1, false);

	int answer = dfs(1);

	cout << answer - 1 << '\n';

	return 0;
}

int dfs(int cur) {
	Visited[cur] = true;
	int nodes = 1;

	for (int next : Graph[cur]) {
		if (Visited[next]) continue;
		nodes += dfs(next);
	}

	return nodes;
}