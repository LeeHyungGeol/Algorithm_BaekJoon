// dfs,bfs문제
// Connected Directed Graph(연결 방향 그래프)에서의 cycle판별하는 문제

// 'The ordering of pensioners in the input is from the youngest to the oldest.'

// 단, 위의 문제 조건에서 가장 어린 사람이 좋아하는 채널(노드)로 가야하므로, 
// int next = graph[cur][0]; 가 되어야 한다.

// 또한, 도착한 노드가 마지막 노드일 경우, 
// graph[cur].size() == 0 이므로, if(!graph[cur].size()) 의 조건문을 추가해준다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, P, cnt;
vector<int> graph[100001];
vector<bool> visited;
vector<bool> visitStack;

bool isCyclicGraph(int cur);

int main() {
	cin >> N >> M >> P;

	visited.resize(M+1, false);
	visitStack.resize(M+1, false);

	for (int i = 0; i < N; ++i) {
		int fav, hate;
		cin >> fav >> hate;
		graph[hate].push_back(fav);
	}

	if (isCyclicGraph(P)) {
		cout << -1 << '\n';
	}
	else {
		cout << cnt - 1 << '\n';
	}

	return 0;
}

bool isCyclicGraph(int cur) {
	++cnt;
	visited[cur] = true;
	visitStack[cur] = true;

	if (!graph[cur].size()) {
		return false;
	}

	int next = graph[cur][0];

	if (!visited[next]) {
		if (isCyclicGraph(next)) {
			return true;
		}
	}
	else if (visitStack[next]) {
		return true;
	}
	
	visitStack[cur] = false;

	return false;
}