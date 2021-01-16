//https://exponential-e.tistory.com/34

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
using namespace std;
// 2^20 = 1000000, 21은 각 노드의 몇 (2^i)번째 부모인가
//이진트리에서 전체 노드가 100만개 있다고 가정했을때 대략 20레벨이면 충분하니까 10만이면 들고도 남는다.
#define LOG 21
int N, M;//N(2 ≤ N ≤ 100,000)개의 정점, 두 노드의 쌍 M(1 ≤ M ≤ 100,000)
int d[100001] = { 0 };
bool isDepthCounted[100001];
int parent[100001][LOG] = { 0 };
vector<int> graph[100001];
void dfs(int cur, int depth) {// 루트 노드부터 시작하여 깊이(depth)를 구하는 함수
	d[cur] = depth;
	isDepthCounted[cur] = true;

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (isDepthCounted[next]) continue;//이전에 깊이를 구한 적이 있다면 continue
		parent[next][0] = cur;//2^0=1, 한칸 위에 있는 부모 관계만 설정한다.
		dfs(next, depth + 1);
	}
}
void setParent() {// 전체 부모 관계를 설정하는 함수
	dfs(1, 0);//루트는 1번이다.

	// 작은 j부터 배열을 채워가면서 전체 배열을 채울 수 있다.
	// i에서 2^(j+1)번 이동한 후의 정점은 i에서 2^j번*2번 이동하는 것
	// parent[i][j+1] = parent[ parent[i][j] ][j]
	for (int j = 1; j < LOG; ++j) {
		for (int i = 1; i <= N; ++i) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}
int LCA(int a, int b) {// A와 B의 최소 공통 조상을 찾는 함수
	if (d[a] > d[b])//b노드가 더 깊도록 설정한다.
		swap(a, b);
	for (int i = LOG - 1; i >= 0;--i) {//깊이가 동일하도록 b노드를 이동
		if (d[b] - d[a] >= 1 << i)
			b = parent[b][i];
	}

	// 부모가 같아지도록 
	if (a == b) return a;
	for (int i = LOG - 1; i >= 0; --i) {
		// 조상을 향해 거슬러 올라가기
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	return parent[a][0];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int from, to;
	for (int i = 1; i <= N - 1; ++i) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	setParent();

	cin >> M;
	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}

	return 0;
}
