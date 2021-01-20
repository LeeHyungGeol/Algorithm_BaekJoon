//https://justicehui.github.io/ps/2019/07/28/BOJ13511/
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define LOG 21
int parent[100001][21];
ll c[100001];
int d[100001];
bool isDepthCounted[100001];
vector<pii> graph[100001];
int N, M;
void dfs(int cur, int depth, ll cost) {
	d[cur] = depth;
	c[cur] = cost;
	isDepthCounted[cur] = true;

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i].second;
		if (isDepthCounted[next]) continue;
		parent[next][0] = cur;
		ll nCost = cost + graph[cur][i].first;
		dfs(next, depth + 1, nCost);
	}
}
void setParent() {
	dfs(1, 0, 0);
	for (int i = 1; i < LOG; ++i) {
		for (int j = 1; j <= N; ++j) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
}
int LCA(int a,int b) {
	if (d[a] > d[b])
		swap(a, b);
	for (int i = LOG - 1; i >= 0; --i) {
		if (d[b] - d[a] >= 1 << i)
			b = parent[b][i];
	}
	if (a == b) return a;
	for (int i = LOG - 1; i >= 0; --i) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}
ll getCost(int a, int b) {
	int lca = LCA(a, b);
	return c[a] + c[b] - (c[lca] * 2);
}
int getKthNode(int a, int b, int k) {
	int lca = LCA(a, b);
	int leftDist = d[a] - d[lca];
	int rightDist = d[b] - d[lca];
	if (k <= leftDist + 1) {
		int dist = k - 1;
		for (int i = LOG - 1; i >= 0; --i) {
			if (dist >= 1 << i) {
				dist -= 1 << i;
				a = parent[a][i];
			}
		}
		return a;
	}
	else {
		int dist = rightDist - (k - (leftDist + 1));
		for (int i = LOG - 1; i >= 0; --i) {
			if (dist >= 1 << i) {
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
	int Case, u, v, k;
	for (int i = 0; i < M; ++i) {
		cin >> Case;
		if (Case == 1) {
			cin >> u >> v;
			cout << getCost(u, v) << '\n';
		}
		else if (Case == 2) {
			cin >> u >> v >> k;
			cout << getKthNode(u, v, k) << '\n';
		}
	}
}