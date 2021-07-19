// dfs,bfs����
// Connected Directed Graph(���� ���� �׷���)������ cycle�Ǻ��ϴ� ����

// 'The ordering of pensioners in the input is from the youngest to the oldest.'

// ��, ���� ���� ���ǿ��� ���� � ����� �����ϴ� ä��(���)�� �����ϹǷ�, 
// int next = graph[cur][0]; �� �Ǿ�� �Ѵ�.

// ����, ������ ��尡 ������ ����� ���, 
// graph[cur].size() == 0 �̹Ƿ�, if(!graph[cur].size()) �� ���ǹ��� �߰����ش�.

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