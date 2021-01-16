//https://jason9319.tistory.com/95

//최소 공통 조상(LCA) 찾기 알고리즘 //LCA: Lowest Common Ancestor

//1. 모든 노드에 대한 깊이(depth)를 계산//DFS 이용
//2. 최소 공통 조상을 찾을 두 노드를 확인한다.
//		2-1) 먼저 두 노드의 깊이(depth)가 동일하도록 거슬러 올라간다.
//		2-2) 이후에 부모가 같아질 때까지 반복적으로 두 노드의 부모 방향으로 거슬러 올라간다.
//3. 모든 LCA(a, b) 연산에 대하여 2번의 과정을 반복한다.

//LCA 심화
//각 노드가 거슬러 올라가는 속도를 빠르게 만드는 방법
//2의 제곱 형태로 거슬러 올라가도록 하면 O(logN)의 시간 복잡도를 보장한다.
//메모리를 조금 더 사용하여 각 노드에 대하여 2^i번째 부모에 대한 정보를 기록한다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define LOG 21
typedef pair<int, int> pii;
int N, K;//(2 ≤ N ≤ 100,000), (1 ≤ K ≤ 100,000)
int parent[100001][LOG];
int MIN[100001][LOG];
int MAX[100001][LOG];
int d[100001];
bool isDepthCounted[100001];
vector<pii> graph[100001];
void dfs(int cur, int depth) {
	d[cur] = depth;
	isDepthCounted[cur] = true;

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i].second;
		if (isDepthCounted[next]) continue;
		parent[next][0] = cur;
		MIN[next][0] = graph[cur][i].first;
		MAX[next][0] = graph[cur][i].first;
		dfs(next, depth + 1);
	}
}
void setParent() {
	dfs(1, 0);
	for (int i = 1; i < LOG; ++i) {
		for (int j = 1; j <= N; ++j) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			MIN[j][i] = min(MIN[j][i - 1], MIN[parent[j][i - 1]][i - 1]);
			MAX[j][i] = max(MAX[j][i - 1], MAX[parent[j][i - 1]][i - 1]);
		}
	}
}
pii LCA(int a, int b) {
	int retMin = 10000001;//도로의 길이는 1,000,000보다 작거나 같은 양의 정수이다.
	int retMax = -1;
	if (d[a] > d[b])
		swap(a, b);
	for (int i = LOG - 1; i >= 0; --i) {
		if (d[b] - d[a] >= 1 << i) {
			retMin = min(retMin, MIN[b][i]);
			retMax = max(retMax, MAX[b][i]);
			b = parent[b][i];
		}
	}

	if (a == b) return { retMin, retMax };
	for (int i = LOG - 1; i >= 0; --i) {
		if (parent[a][i] != parent[b][i]) {
			retMin = min(retMin, min(MIN[a][i], MIN[b][i]));
			retMax = max(retMax, max(MAX[a][i], MAX[b][i]));
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	retMin = min(retMin, min(MIN[a][0], MIN[b][0]));
	retMax = max(retMax, max(MAX[a][0], MAX[b][0]));
	return { retMin, retMax };
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

	cin >> K;
	int a, b;
	for (int i = 0; i < K; ++i) {
		cin >> a >> b;
		cout << LCA(a, b).first << " " << LCA(a, b).second << '\n';
	}
	return 0;
}