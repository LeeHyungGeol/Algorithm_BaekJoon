// bfs�� �ִܰŸ��� ã�� ����
// �ִܰŸ���� Dijkstra�� bfs�� ���÷��� �ϴµ�, �� ���������� ������ ����ġ�� ���� 1�� �����ϹǷ� BFS�� Ǯ�� �����ϴ�.

// ���� ���� �̵��� ������ �Ÿ��� 1�� �������Ѿ� �ϴµ�, 
// �� �κп��� queue�� pair<int, int> �� { ����ȣ, �Ÿ� }�� �Բ� ó�����־��µ�,
// �ٸ� ����� Ǯ�̸� ���� visited �迭�� �Ÿ��� ó�����ִ� ���� ���Ҵ�.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int N, M, K, X;
vector<int> graph[300001];
bool visited[300001];
int visited2[300001] = { 0, };

vector<int> bfs();
vector<int> bfs2();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; ++i) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
	}

	fill(visited2, visited2 + N + 1, -1);

	// 	vector<int> results = bfs();
	vector<int> results = bfs2();

	for (int i = 0; i < results.size(); ++i) {
		cout << results[i] << '\n';
	}

	return 0;
}

vector<int> bfs() {
	queue<pii> q;
	vector<int> results;

	q.push({ X,0 });
	visited[X] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		++dist;

		q.pop();

		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, dist});

				if (dist == K) {
					results.push_back(next);
				}
			}
		}
	}

	if (results.empty()) {
		results.push_back(-1);
	}
	else {
		sort(results.begin(), results.end());
	}

	return results;
}

vector<int> bfs2() {
	queue<int> q;
	vector<int> results;

	q.push(X);
	visited2[X] = 0;

	while (!q.empty()) {
		int cur = q.front();

		q.pop();

		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (visited2[next] == -1) {
				q.push(next);
				visited2[next] = visited2[cur] + 1;
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (visited2[i] == K) {
			results.push_back(i);
		}
	}

	if (results.empty()) {
		results.push_back(-1);
	}

	sort(results.begin(), results.end());
	
	return results;
}