//위상 정렬(Topological Sort): '사이클이 없는 방향 그래프'의 '모든 노드를 방향성에 거스르지 않도록 순서대로 나열'하는 것을 의미
//사이클이 없는 방향 그래프: DAG(Directed Acyclic Graph)
//진입차수(Indegree): 특정한 노드로 들어오는 간선의 개수
//진출차수(Outdegree): 특정한 노드에서 나가는 간선의 개수
//Stack을 활용한 DFS로 풀거나 Queue로 위상정렬(Topological Sort)로 풀 수 있다.

//위상 정렬(Topological Sort)은 DAG에 대해서만 수행이 가능하다.
//'모든 원소를 방문하기 전에 큐가 빈다면 '사이클이 존재한다고 판단'할 수 있다.
//위상 정렬 알고리즘의 시간 복잡도: O(V+E) : 차례대로 모든 노드를 확인하며 각 노드에서 나가는 간선을 차례대로 제거해야 한다.

//단순한 queue가 아닌 '우선순위 큐(priority_queue)'를 이용한다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> InDegree;
vector<vector<int>> Graph;

vector<int> topologicalSort();

int main() {
	cin >> N >> M;

	Graph.resize(N + 1);
	InDegree.resize(N + 1, 0);

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		Graph[a].push_back(b);
		++InDegree[b];
	}

	vector<int> answer = topologicalSort();

	for (int x : answer) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}

vector<int> topologicalSort() {
	priority_queue<int> pq;
	vector<int> answer;

	for (int i = 1; i <= N; ++i) {
		if (InDegree[i] == 0) {
			pq.push(-i);
		}
	}

	while (!pq.empty()) {
		int cur = -pq.top();
		answer.push_back(cur);
		pq.pop();

		for (int next : Graph[cur]) {
			--InDegree[next];
			if (InDegree[next] == 0) {
				pq.push(-next);
			}
		}
	}

	return answer;
}