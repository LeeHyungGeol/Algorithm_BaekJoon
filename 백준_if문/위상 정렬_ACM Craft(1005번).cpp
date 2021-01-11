//위상 정렬(Topological Sort): """"사이클이 없는 방향 그래프"""의 """모든 노드를 방향성에 거스르지 않도록 순서대로 나열"""하는 것을 의미
//사이클이 없는 방향 그래프: DAG(Directed Acyclic Graph)
//진입차수(Indegree): 특정한 노드로 들어오는 간선의 개수
//진출차수(Outdegree): 특정한 노드에서 나가는 간선의 개수
//Stack을 활용한 DFS로 풀거나 Queue로 위상정렬(Topological Sort)로 풀 수 있다.
//큐를 이용한 위상 정렬 알고리즘의 동작 과정: 1. 진입차수가 0인 모든 노드를 큐에 넣는다.
//											  2. 큐가 빌 때까지 다음의 과정을 반복한다.
//											     2-1) 큐에서 원소를 꺼내 해당 노드에서 나가는 간선을 그래프에서 제거한다.
//												 2-2) 새롭게 진입차수가 0이 된 노드를 큐에 넣는다.
//			결과적으로 """각 노드가 큐에 들어온 순서가 위상 정렬을 수행한 결과"""와 같다.

//위상 정렬(Topological Sort)은 DAG에 대해서만 수행이 가능하다.
//""모든 원소를 방문하기 전에 큐가 빈다면 """사이클이 존재한다고 판단"""할 수 있다.
//위상 정렬 알고리즘의 시간 복잡도: O(V+E) : 차례대로 모든 노드를 확인하며 각 노드에서 나가는 간선을 차례대로 제거해야 한다.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring> //memset
using namespace std;
int T, N, K, W;//2 ≤ N ≤ 1000, 1 ≤ K ≤ 100, 000
int time[1001] = { 0 };
int inDegree[1001] = { 0 };
vector<int> graph[1001];
void topologicalSort() {
	vector<int> result(N + 1);
	queue<int> q;

	for (int i = 1; i <= N; ++i) {
		result[i] = time[i];
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		
		q.pop();
		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i];
			result[next] = max(result[next], result[cur] + time[next]);
			inDegree[next]--;
			if (inDegree[next] == 0)
				q.push(next);
		}
	}
	cout << result[W] << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; ++t) {
		memset(time, 0, sizeof(time));
		memset(graph, 0, sizeof(graph));
		memset(inDegree, 0, sizeof(inDegree)); 

		cin >> N >> K;
		for (int i = 1; i <= N; ++i)
			cin >> time[i];
		int from, to;
		for (int i = 1; i <= K; ++i) {
			cin >> from >> to;
			graph[from].push_back(to);
			inDegree[to]++;
		}
		cin >> W;
		topologicalSort();
	}

	return 0;
}