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
//진입차수가 0이 아닌 1이상인 노드가 발생하기 때문이다.
//위상 정렬 알고리즘의 시간 복잡도: O(V+E) : 차례대로 모든 노드를 확인하며 각 노드에서 나가는 간선을 차례대로 제거해야 한다.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;//N(1≤N≤32,000), M(1≤M≤100,000)
int inDegree[32001] = { 0 };
vector<int> graph[32001];
vector<int> topologicalSort() {
	vector<int> result;
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (inDegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		result.push_back(cur);

		q.pop();
		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i];
			inDegree[next] -= 1;
			if (inDegree[next] == 0)
				q.push(next);
		}
	}
	return result;
}
int main() {
	cin >> N >> M;
	int from, to;
	for (int i = 0; i < M; ++i) {
		cin >> from >> to;
		graph[from].push_back(to);//from에서 to로 이동 가능
		inDegree[to]+=1;//진입차수를 1 증가
	}
	vector<int> ans = topologicalSort();

	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}