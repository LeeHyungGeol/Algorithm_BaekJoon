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
#include <vector>
#include <queue>
using namespace std;
int v, e;//노드의 개수: v, 간선의 개수: e
int inDegree[100001] = { 0 };//모든 노드에 대한 진입 차수는 0으로 초기화
vector<int> graph[100001];
vector<int> topologicalSort() {
	vector<int> result;//알고리즘 수행 결과를 담은 리스트
	queue<int> q;//큐를 활용한 위상정렬
	for (int i = 1; i <= v; ++i) {
		if (inDegree[i] == 0)//처음 시작할 때 진입 차수가 0인 노드부터 큐에 삽입
			q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		result.push_back(cur);

		q.pop();
		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i];
			inDegree[next] -= 1;
			//inDegree[next]--;
			if (inDegree[next] == 0) {
				q.push(next);
			}
		}
	}
	return result;
}
int main() {
	cin >> v >> e;
	// 방향 그래프의 모든 간선 정보를 입력 받기
	for (int i = 0; i < e; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); // 정점 A에서 B로 이동 가능
		// 진입 차수를 1 증가
		inDegree[b] += 1;
	}

	vector<int> ans = topologicalSort();

	// 위상 정렬을 수행한 결과 출력
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}
