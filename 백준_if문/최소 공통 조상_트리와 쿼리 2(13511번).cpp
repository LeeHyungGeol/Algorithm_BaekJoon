//트리 상의 경로에서 k번째 정점을 구하는 문제
#include <iostream>
#include <vector>
using namespace std;
#define LOG 21
typedef pair<int, int> pii;
typedef long long ll;
int N, M;// (2 ≤ N ≤ 100,000),쿼리의 개수 M (1 ≤ M ≤ 100,000)
int u, v, k;
int Case;
int lca = 0;
int d[100001];
bool isDepthCounted[100001];
int parent[100001][LOG];
ll cost[100001][LOG];
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
			cost[j][i] = cost[j][i - 1] + cost[parent[j][i - 1]][i - 1];
		}
	}
}
int LCA(int a, int b) {
	ll sum = 0;
	if (d[a] > d[b])
		swap(a, b);
	for (int i = LOG - 1; i >= 0; --i) {
		if (d[b] - d[a] >= 1 << i) {
			sum += cost[b][i];
			b = parent[b][i];
		}
	}
	if (a == b) {
		lca = a;
		return sum;
	} ////
	for (int i = LOG - 1; i >= 0; --i) {
		if (parent[a][i] != parent[b][i]) {
			sum += cost[a][i];
			sum += cost[b][i];
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	sum += cost[a][0];
	sum += cost[b][0];
	lca = parent[a][0];//k번째 노드를 찾기 위해서 사용할 최소 공통 조상
	return sum;
}
int LCA2(int a, int b, int k) {
	LCA(a, b);//최소 공통 조상을 찾기 위해서
	int leftDist = d[a] - d[lca];
	int rightDist = d[b] - d[lca];
	if (k <= leftDist + 1) {
		int dist = k - 1;
		for (int i = LOG - 1; i >= 0; --i) {
			if (dist >= 1 << i) { //if ((n & (1 << bit)) > 0) 
				dist -= 1 << i;
				a = parent[a][i];
			}
		}
		return a;
	}
	else {
		int dist = rightDist - (k - (leftDist + 1));
		for (int i = LOG - 1; i >= 0; --i) {
			if (dist >= 1 << i) { //if ((n & (1 << bit)) > 0) 
				dist -= 1 << i;
				b = parent[b][i];
			}
		}
		return b;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int from, to, dist;
	for (int i = 1; i <= N - 1; ++i) {
		cin >> from >> to >> dist;
		graph[from].push_back({ dist, to });
		graph[to].push_back({ dist, from });
	}
	setParent();
	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> Case;
		if (Case == 1) {
			cin >> u >> v;
			cout << LCA(u, v) << '\n';
		}
		else if (Case == 2) {
			cin >> u >> v >> k;
			cout << LCA2(u, v, k) << '\n';
		}
	}
	return 0;
}