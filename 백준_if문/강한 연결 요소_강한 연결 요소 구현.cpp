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

#define MAX 100000//가능한 총 노드의 개수

int id, pa[MAX];//각 노드마다 고유한 번호를 할당
bool finished[MAX];//현재 특정한 노드에 대한 DFS가 끝났는지 확인할 수 있도록 한다.
vector<int> adj[MAX];//실질적으로 인접한 노드를 담는 배열
vector<vector<int>> SCC;//SCC는 한 그래프 내에서 여러 개가 나올 수 있기 때문에 2차원 벡터로 구현
stack<int> s;

//DFS는 총 정점의 개수만큼 실행한다.
int dfs(int x) {
	//노드마다 고유한 번호를 할당
	pa[x] = ++id;//맨 처음에 부모로 설정된 값
	s.push(x); //stack에 자기 자신을 삽입

	//parent값을 통해 자신의 부모가 누구인지 확인
	int parent = pa[x];//맨 처음 같은 경우는 자기 자신이 부모가 된다.
	
	//인접한 노드를 하나씩 확인한다.
	for (int i = 0; i < adj[x].size(); ++i) { 
		int next = adj[x][i];
		
		//방문하지 않은 이웃
		//해당 노드를 방문한 적이 없다면 DFS를 수행
		if (pa[next] == 0)
			parent = min(parent, dfs(next));

		//처리 중인 이웃
		//방문은 하였지만, DFS를 수행중인 노드: 현재 stack에 이웃 노드가 들어가 있는 상태 
		//즉,DFS가 끝나지 않은 상태에서 이웃 노드로 갈 수 있다는 점은 이웃 노드가 자신의 부모노드 였음을 알 수 있다.
		else if (!finished[next])//처리중인 이웃이 자신의 부모라면 해당 노드까지 SCC에 포함하기 위해 같은 부모 값을 가지게 한다.
			parent = min(parent, pa[next]);

	}

	//부모노드가 자기 자신인 경우
	if (parent == pa[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;//하나씩 노드를 꺼내면서 처리가 완료되었다고 표시
			//자기 자신의 값, 즉, 부모 값이 나온 경우 반복문을 빠져나간다. 
			if (t == x) break;
		}
		SCC.push_back(scc);
	}

	//자신의 부모 값을 반환한다.
	return parent;
}
int main() {
	int v = 11;
	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[3].push_back(1);
	adj[4].push_back(2);
	adj[4].push_back(5);
	adj[5].push_back(7);
	adj[6].push_back(5); 
	adj[7].push_back(6);
	adj[8].push_back(5);
	adj[8].push_back(9);
	adj[9].push_back(10);
	adj[10].push_back(11);
	adj[11].push_back(3);
	adj[11].push_back(8);

	for (int i = 1; i <= v; ++i) {
		//한번도 방문하지 않은 노드에 대하여 dfs를 수행
		//DFS는 총 정점의 개수만큼 실행한다.
		if (pa[i] == 0) dfs(i);
	}

	cout << "SCC의 개수 : " << SCC.size() << '\n';
	for (int i = 0; i < SCC.size(); ++i) {
		cout << i + 1 << "번째 SCC :";
		for (int j = 0; j < SCC[i].size(); ++j) {
			cout << SCC[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}