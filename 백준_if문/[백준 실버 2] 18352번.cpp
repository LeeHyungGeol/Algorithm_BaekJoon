// bfs로 최단거리를 찾는 문제
// 최단거리라면 Dijkstra나 bfs를 떠올려야 하는데, 이 문제에서는 간선의 가중치가 전부 1로 동일하므로 BFS로 풀면 간단하다.

// 다음 노드로 이동할 때마다 거리를 1씩 증가시켜야 하는데, 
// 이 부분에서 queue에 pair<int, int> 로 { 노드번호, 거리 }를 함께 처리해주었는데,
// 다른 사람의 풀이를 보니 visited 배열로 거리를 처리해주는 것을 보았다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int N, M, K, X;
vector<int> graph[300001];
bool visited[300001];
int visited2[300001] = { 0, };

vector<int> bfs();
vector<int> bfs2();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; ++i) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
	}

	fill(visited2, visited2 + N + 1, -1);

	// 	vector<int> results = bfs();
	vector<int> results = bfs2();

	for (int i = 0; i < results.size(); ++i) {
		cout << results[i] << '\n';
	}

	return 0;
}

vector<int> bfs() {
	queue<pii> q;
	vector<int> results;

	q.push({ X,0 });
	visited[X] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		++dist;

		q.pop();

		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, dist});

				if (dist == K) {
					results.push_back(next);
				}
			}
		}
	}

	if (results.empty()) {
		results.push_back(-1);
	}
	else {
		sort(results.begin(), results.end());
	}

	return results;
}

vector<int> bfs2() {
	queue<int> q;
	vector<int> results;

	q.push(X);
	visited2[X] = 0;

	while (!q.empty()) {
		int cur = q.front();

		q.pop();

		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (visited2[next] == -1) {
				q.push(next);
				visited2[next] = visited2[cur] + 1;
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (visited2[i] == K) {
			results.push_back(i);
		}
	}

	if (results.empty()) {
		results.push_back(-1);
	}

	sort(results.begin(), results.end());
	
	return results;
}