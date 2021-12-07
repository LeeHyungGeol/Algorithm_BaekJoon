// bfs�� �ִܰŸ��� ã�� ����
// �ִܰŸ���� Dijkstra�� bfs�� ���÷��� �ϴµ�, �� ���������� ������ ����ġ�� ���� 1�� �����ϹǷ� BFS�� Ǯ�� �����ϴ�.

// ���� ���� �̵��� ������ �Ÿ��� 1�� �������Ѿ� �ϴµ�, 
// �� �κп��� queue�� pair<int, int> �� { ����ȣ, �Ÿ� }�� �Բ� ó�����־��µ�,
// �ٸ� ����� Ǯ�̸� ���� visited �迭�� �Ÿ��� ó�����ִ� ���� ���Ҵ�.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, X;
vector<vector<int>> Graph;
vector<int> Dist;

vector<int> bfs(int start);

int main() {

	cin >> N >> M >> K >> X;

	Graph.resize(N + 1);
	Dist.resize(N + 1, -1);

	for (int i = 0, a, b; i < M; ++i) {
		cin >> a >> b;
		Graph[a].push_back(b);
	}

	vector<int> answer = bfs(X);

	for (int n : answer) {
		cout << n << '\n';
	}

	return 0;
}

vector<int> bfs(int start) {
	vector<int> result;
	queue<int> q;

	q.push(start);
	Dist[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : Graph[cur]) {
			if (Dist[next] != -1) continue;
			Dist[next] = Dist[cur] + 1;
			q.push(next);
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (Dist[i] == K) result.push_back(i);
	}

	if (result.empty()) result.push_back(-1);

	return result;
}