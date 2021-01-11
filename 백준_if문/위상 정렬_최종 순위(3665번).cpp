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
//""모든 원소를 방문하기 전에"" 큐가 빈다면 """사이클이 존재한다고 판단"""할 수 있다.
//진입차수가 0이 아닌 1이상인 노드가 발생하기 때문이다.
//위상 정렬 알고리즘의 시간 복잡도: O(V+E) : 차례대로 모든 노드를 확인하며 각 노드에서 나가는 간선을 차례대로 제거해야 한다.
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int T, n, m;// 테스트 케이스는 100개를 넘지 않는다.  (2 ≤ n ≤ 500),  (0 ≤ m ≤ 25000)
int inDegree[501] = { 0 };
bool graph[501][501];
void topologicalSort() {
	vector<int> ans;
	queue<int> q;
	bool certain = true;

	for (int i = 1; i <= n; ++i) {
		if (inDegree[i] == 0)
			q.push(i);
	}
	//모든 원소를 방문한다. 
	while (!q.empty()) {//for(int i = 0; i < n; ++i)으로도 대체 가능
		if (q.size() >= 2) {//진입 차수가 0인 노드가 2개 이상인 경우
			certain = false;//확실한 순위를 찾을 수 없다.
			break;
		}

		int cur = q.front();
		ans.push_back(cur);

		q.pop();
		for (int i = 1; i <= n; ++i) {
			if (graph[cur][i]) {
				inDegree[i]--;
				if (inDegree[i] == 0)
					q.push(i);
			}
		}
	}

	if (!certain)
		cout << "?" << '\n';
	else if (ans.size() == n) {//올해 순위를 온전히 정한 경우
		for (int i = 0; i < n; ++i)//vector의 size가 노드의 개수와 같다.
			cout << ans[i] << ' ';
		cout << '\n';
	}
	else {//데이터에 일관성이 없어서 순위를 정할 수 없는 경우
		//모든 원소를 방문하기 전에 queue가 비는 경우 : 사이클이 발생한 경우
		cout << "IMPOSSIBLE" << '\n';
	}
}
int main() {
	cin >> T;
	for (int t = 0; t < T; ++t) {
		memset(inDegree, 0, sizeof(inDegree));
		memset(graph, false, sizeof(graph));

		cin >> n;

		vector<int> rank(n);
		for (int i = 0; i < n; ++i)
			cin >> rank[i];

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				graph[rank[i]][rank[j]] = true;
				inDegree[rank[j]]++;
			}
		}

		cin >> m;
		int a, b;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			if (graph[a][b]) {
				graph[a][b] = false;
				graph[b][a] = true;
				inDegree[b]--;
				inDegree[a]++;
			}
			else {
				graph[a][b] = true;
				graph[b][a] = false;
				inDegree[b]++;
				inDegree[a]--;
			}
		}

		topologicalSort();
	}
	return 0;
}