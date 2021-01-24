//강한 연결 요소(Strongly Connected Componensts): 강하게 연결된 정점 집합
//같은 SCC에 속하는 두 정점은 서로 도달이 가능하다.
//사이클이 발생하는 경우 무조건 SCC에 해당한다.
//방향 그래프일 때만 의미가 있다. 무향 그래프라면 그 그래프 전체는 무조건 SCC이다.
//코사라주 알고리즘(Kosaraju's Algorithm), 타잔 알고리즘(Tarjan's Algorithm)

//타잔 알고리즘(Tarjan's Algorithm): 모든 정점에 대해 DFS를 수행하여 SCC를 찾는 알고리즘
//1. DFS를 수행하면서 부모 값을 확인한다. 
//2. Stack에서 해당 부모 값이 나올 때 까지 원소를 뽑아낸다. 

//타잔 알고리즘의 성질 중 하나가 SCC를 위상 정렬의 역순으로 추출한다는 것
//강한 연결 요소(SCC)는 그 자체로는 큰 의미가 없지만, 위상 정렬(Topological Sort)과 함께 했을 때 의미가 더 커진다.
//""각 SCC 집합을 정점""으로 하는 ""위상정렬""을 수행 가능하다.
//강한 연결 요소 알고리즘의 시간 복잡도는 O(V+E)이다 : 모든 정점에 대해서 DFS를 수행, 모든 간선에 대해서 하나씩 확인한다.

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX 10001

int V, E;//V(1 ≤ V ≤ 10,000), E(1 ≤ E ≤ 100,000)
int idx, pa[MAX];
bool finished[MAX];
vector<int> graph[MAX];
vector<vector<int>> SCC;
stack<int> s;

int dfs(int cur) {
	pa[cur] = ++idx;
	s.push(cur);
	int parent = pa[cur];

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (pa[next] == 0) parent = min(parent, dfs(next));
		else if (!finished[next]) parent = min(parent, pa[next]);
	}

	if (parent == pa[cur]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			finished[t] = true;
			scc.push_back(t);
			if (t == cur) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}

	return parent;
}
int main() {
	cin >> V >> E;
	int from, to;
	for (int i = 0; i < E; ++i) {
		cin >> from >> to;
		graph[from].push_back(to);
	}

	for (int i = 1; i <= V; ++i)
		if (pa[i] == 0) dfs(i);

	sort(SCC.begin(), SCC.end());

	cout << SCC.size() << '\n';
	for (int i = 0; i < SCC.size(); ++i) {
		for (int j = 0; j < SCC[i].size(); ++j) {
			cout << SCC[i][j] << ' ';
		}
		cout << "-1\n";
	}
	return 0;
}