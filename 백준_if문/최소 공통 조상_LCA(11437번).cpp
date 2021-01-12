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
using namespace std;
int N, M;//N(2 ≤ N ≤ 50,000)개의 정점, 두 노드의 쌍 M(1 ≤ M ≤ 10,000)
int d[50001] = { 0 };
bool isDepthCounted[50001];
int parent[50001] = { 0 };
vector<int> graph[50001];
void dfs(int cur, int depth) {//root노드부터 시작해서 각 노드의 깊이(depth)를 계산하는 DFS
	d[cur] = depth;//깊이를 계산
	isDepthCounted[cur] = true;//현재 노드의 깊이가 계산되었다.

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (isDepthCounted[next]) continue;//이전에 깊이(depth)를 구한 적이 있다면 continue
		parent[next] = cur;//자식 노드(next)의 부모 노드(parent)는 현재 노드(cur)
		dfs(next, depth + 1);
	}
}
int LCA(int a, int b) {//노드 a와 노드 b의 최소 공통 조상을 찾는 함수
	while (d[a] != d[b]) {//두 노드의 깊이가 같아지도록 부모로 거슬러 올라간다.
		if (d[a] > d[b])
			a = parent[a];
		else
			b = parent[b];
	}
	while (a != b) {//노드가 같아지도록 부모로 거슬러 올라간다.
		a = parent[a];
		b = parent[b];
	}
	return a;
}

int main() {//-1272ms
	ios_base::sync_with_stdio(false);//-816ms
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int from, to;
	for (int i = 1; i <= N - 1; ++i) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	//root노드는 1번 노드
	dfs(1, 0);//모든 노드에 대한 깊이(depth)를 계산

	cin >> M;
	int a, b, ans = 0;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		ans = LCA(a, b);
		cout << ans << '\n';
	}
	return 0;
}

