//트리 상의 경로에서 k번째 정점을 구하는 문제
#include <iostream>
#include <vector>
using namespace std;
#define LOG 21
typedef pair<int, int> pii;
int N, M;// (2 ≤ N ≤ 100,000),쿼리의 개수 M (1 ≤ M ≤ 100,000)
int u, v, k;
int d[100001];
bool isDepthCounted[100001];
int parent[100001][LOG];
int cost[100001][LOG];
vector<pii> graph[100001];
void dfs(int cur, int depth) {
	d[cur] = depth;
	isDepthCounted[cur] = true;

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i].second;
		if (isDepthCounted[next]) continue;
		parent[next][0] = cur;
		cost[next][0] = graph[cur][i].first;
		dfs(next, depth + 1);
	}
}
void setParent() {
	dfs(1, 0);
	for (int i = 1; i < LOG - 1; ++i) {
		for (int j = 1; j <= N; ++j) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			cost[j][i] = cost[cost[j][i - 1]][i - 1];
		}
	}
}
pii LCA(int a, int b) {
	int sum = 0;

}
int main() {
	cin >> N;
	int from, to, dist;
	for (int i = 1; i <= N - 1; ++i) {
		cin >> from >> to >> dist;
		graph[from].push_back({ dist, to });
		graph[to].push_back({ dist, from });
	}

	cin >> M;
	int Case;
	for (int i = 0; i < M; ++i) {
		cin >> Case;
		if (Case == 1) {
			cin >> u >> v;
			cout << LCA(u, v).first << '\n';
		}
		else if (Case == 2) {
			cin >> u >> v >> k;
			cout << LCA(u, v).second << '\n';
		}
	}
	return 0;
}