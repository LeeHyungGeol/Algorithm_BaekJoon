// bfs로 최단거리를 찾는 문제
// 최단거리라면 Dijkstra나 bfs를 떠올려야 하는데, 이 문제에서는 간선의 가중치가 전부 1로 동일하므로 BFS로 풀면 간단하다.

// 다음 노드로 이동할 때마다 거리를 1씩 증가시켜야 하는데, 
// 이 부분에서 queue에 pair<int, int> 로 { 노드번호, 거리 }를 함께 처리해주었는데,
// 다른 사람의 풀이를 보니 visited 배열로 거리를 처리해주는 것을 보았다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, X;
vector<vector<int>> Graph;
vector<int> Dist;

vector<int> bfs(int start);

int main() {

	cin >> N >> M >> K >> X;

	Graph.resize(N + 1);
	Dist.resize(N + 1, -1);

	for (int i = 0, a, b; i < M; ++i) {
		cin >> a >> b;
		Graph[a].push_back(b);
	}

	vector<int> answer = bfs(X);

	for (int n : answer) {
		cout << n << '\n';
	}

	return 0;
}

vector<int> bfs(int start) {
	vector<int> result;
	queue<int> q;

	q.push(start);
	Dist[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : Graph[cur]) {
			if (Dist[next] != -1) continue;
			Dist[next] = Dist[cur] + 1;
			q.push(next);
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (Dist[i] == K) result.push_back(i);
	}

	if (result.empty()) result.push_back(-1);

	return result;
}