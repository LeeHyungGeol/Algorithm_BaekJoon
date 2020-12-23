//간선에 가중치와 방향성이 없는 임의의 루트 있는 트리가 주어졌을 때, 아래의 쿼리에 답해보도록 하자.
//정점 U를 루트로 하는 서브트리에 속한 정점의 수를 출력한다.
//->dfs 혹은 bfs로 헤보자
//트리의 부모 찾기 문제(11725번)과 같이 일반적인 dfs, bfs로 돌리면 틀린다.
//루트의 번호 R에 대한 것을 활용하자.
//dp문제인 것을 까먹고 있었다. 메모이제이션을 하자.
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
int N;//정점의 수 N (2 ≤ N ≤ 10^5)
int R;//루트의 번호 R ( 1 ≤ R ≤ N)
int Q;//쿼리의 수 Q (1 ≤ Q ≤ 10^5)
int cnt = 0;
bool visited[100001];
int dp[100001] = { 0 };
vector<int> tree[100001];
int dfs(int start);
//void bfs(int start);
//void countSubTreeByBfs(int start);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> R >> Q;
	int from, to;
	for (int i = 0; i < N - 1; ++i) {
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);
	}
	dfs(R);
	//bfs(R);
	int query;
	for (int i = 0; i < Q; ++i) {
		cin >> query;
		//cnt = 0;
		//countSubTreeByBfs(query);
		//cout <<" cnt : "<< cnt << '\n';
		cout << dp[query] << '\n';
	}

	return 0;
}
int dfs(int cur) {
	if (dp[cur] != 0) return dp[cur];
	visited[cur] = true;
	dp[cur] = 1;
	for (int i = 0; i < tree[cur].size(); ++i) {
		int next = tree[cur][i];
		if (!visited[next]) {
			visited[next] = true;
			dp[cur] += dfs(next);
		}
	}
	return dp[cur];
}
//void bfs(int start) {
//	fill(visited, visited + 100001, false);
//	queue<int> q;
//	q.push(start);
//	visited[start] = true;
//
//	while (!q.empty()) {
//		int cur = q.front();
//
//		q.pop();
//		for (int i = 0; i < tree[cur].size(); ++i) {
//			int next = tree[cur][i];
//			
//			if (!visited[next]) {
//				parent[next] = cur;
//				visited[next] = true;
//				q.push(next);
//			}
//		}
//	}
//}
//void countSubTreeByBfs(int start) {
//	fill(visited, visited + 100001, false);
//	queue<int> q;
//	q.push(start);
//	visited[start] = true;
//	cnt++;
//	while (!q.empty()) {
//		int cur = q.front();
//
//		q.pop();
//		for (int i = 0; i < tree[cur].size(); ++i) {
//			int next = tree[cur][i];
//			//cout << next << ' ';
//			if (parent[next] == start)
//				continue;
//			if (!visited[next]) {
//				cnt++;				
//				visited[next] = true;
//				q.push(next);
//			}
//		}
//	}
//}
