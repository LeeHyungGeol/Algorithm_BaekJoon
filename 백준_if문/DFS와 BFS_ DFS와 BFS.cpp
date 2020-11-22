#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visitedDFS[1001];
bool visitedBFS[1001];
void dfs(int v, vector<vector<int>>& graph);
void bfs(int start, vector<vector<int>>& graph);

int main() {
	
	int N, M, V, v, w;
	cin >> N >> M >> V;
	vector<vector<int>> graph(N + 1, vector<int>{});
	for (int i = 1; i <= M; ++i) {
		cin >> v >> w;
		graph[v].push_back(w);
		graph[w].push_back(v);
	}
	for (int i = 1; i < graph.size(); ++i)
		sort(graph[i].begin(), graph[i].end());
	dfs(V, graph);
	cout << '\n';
	bfs(V, graph);
	cout << '\n';
	return 0;
}
void dfs(int v, vector<vector<int>>& graph) {
	// 현재 노드를 방문 처리
	visitedDFS[v] = true;
	cout << v << ' ';
	// 현재 노드와 연결된 다른 노드를 재귀적으로 방문
	for (int i = 0; i < graph[v].size(); ++i) {
		int w = graph[v][i];
		if (!visitedDFS[w])
			dfs(w, graph);
	}
}
void bfs(int start, vector<vector<int>>& graph) {
	queue<int> que;
	que.push(start);
	// 현재 노드를 방문 처리
	visitedBFS[start] = true;
	// 큐가 빌 때까지 반복
	while (!que.empty()) {
		// 큐에서 하나의 원소를 뽑아 출력
		int v = que.front();
		cout << v << ' ';
		que.pop();
		for (int i = 0; i < graph[v].size(); ++i) {
			int w = graph[v][i];
			// 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
			if (!visitedBFS[w]) {
				que.push(w);
				visitedBFS[w] = true;
			}
		}
	}
}