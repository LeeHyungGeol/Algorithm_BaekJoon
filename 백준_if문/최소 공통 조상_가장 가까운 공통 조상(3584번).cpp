//최소 공통 조상(LCA) 찾기 알고리즘 //LCA: Lowest Common Ancestor

//1. 모든 노드에 대한 깊이(depth)를 계산//DFS 이용
//2. 최소 공통 조상을 찾을 두 노드를 확인한다.
//		2-1) 먼저 두 노드의 깊이(depth)가 동일하도록 거슬러 올라간다.
//		2-2) 이후에 부모가 같아질 때까지 반복적으로 두 노드의 부모 방향으로 거슬러 올라간다.
//3. 모든 LCA(a, b) 연산에 대하여 2번의 과정을 반복한다.

//"""LCA 기본"""
//매 쿼리마다 부모 방향으로 거슬러 올라가기 위해 최악의 경우 O(N)의 시간 복잡도가 요구된다.
//따라서 모든 쿼리를 처리할 때의 시간 복잡도는 O(N*M)이다.
#include <iostream>
#include <vector>
#include <cstring>//memset
using namespace std;
int parent[10001] = { 0 };
int d[10001] = { 0 };
bool isDepthCounted[10001];
vector<int> graph[10001];
void dfs(int cur, int depth) {
	isDepthCounted[cur] = true;
	d[cur] = depth;
	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (isDepthCounted[next]) continue;
		dfs(next, depth + 1);
	}
}
int LCA(int a, int b) {
	while (d[a] != d[b]) {
		if (d[a] > d[b])
			a = parent[a];
		else
			b = parent[b];
	}
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}
int T, N;//트리를 구성하는 노드의 수(2 ≤ N ≤ 10,000)
int main() {
	cin >> T;
	for (int t = 0; t < T; ++t) {
		memset(d, 0, sizeof(d));
		memset(parent, 0, sizeof(parent));
		memset(isDepthCounted, false, sizeof(isDepthCounted));
		memset(graph, 0, sizeof(graph));

		cin >> N;
		int A, B;
		for (int i = 1; i <= N - 1; ++i) {
			cin >> A >> B;
			graph[A].push_back(B);
			graph[B].push_back(A);
			parent[B] = A;
		}

		int root = -1;
		for (int i = 1; i <= N; i++) {
			if (parent[i] == 0) {
				root = i;
				break;
			}
		}

		dfs(root, 0);

		int v1, v2;
		cin >> v1 >> v2;
		cout << LCA(v1, v2) << '\n';
	}
	return 0;
}
