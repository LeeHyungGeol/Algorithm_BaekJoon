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
	// ���� ��带 �湮 ó��
	visitedDFS[v] = true;
	cout << v << ' ';
	// ���� ���� ����� �ٸ� ��带 ��������� �湮
	for (int i = 0; i < graph[v].size(); ++i) {
		int w = graph[v][i];
		if (!visitedDFS[w])
			dfs(w, graph);
	}
}
void bfs(int start, vector<vector<int>>& graph) {
	queue<int> que;
	que.push(start);
	// ���� ��带 �湮 ó��
	visitedBFS[start] = true;
	// ť�� �� ������ �ݺ�
	while (!que.empty()) {
		// ť���� �ϳ��� ���Ҹ� �̾� ���
		int v = que.front();
		cout << v << ' ';
		que.pop();
		for (int i = 0; i < graph[v].size(); ++i) {
			int w = graph[v][i];
			// �ش� ���ҿ� �����, ���� �湮���� ���� ���ҵ��� ť�� ����
			if (!visitedBFS[w]) {
				que.push(w);
				visitedBFS[w] = true;
			}
		}
	}
}