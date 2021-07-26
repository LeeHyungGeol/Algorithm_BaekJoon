// 위상정렬(topological sort) 문제
// 우선순위 큐(priority_queue), 큐(queue)를 쓰든, 이 문제에선 아무 상관이 없다.
// 싸이클(cycle)이 발생한 경우 == 모든 원소를 방문하기 전에 queue가 빈다 == vector.size() != N(모든 노드의 개수) 이다.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> indegree;
vector<int> graph[1001];

void topologicalSort();

int main() {
	cin >> N >> M;

	indegree.resize(N + 1, 0);

	int temp, a, b = 0;

	for (int i = 0; i < M; ++i) {
		cin >> temp >> a;

		for (int j = 1; j < temp; ++j) {	
			cin >> b;
			graph[a].push_back(b);
			++indegree[b];
			a = b;
		}
	}

	topologicalSort();

	return 0;
}

void topologicalSort() {
	//queue<int> q;
	priority_queue<int> pq;
	vector<int> answer;

	for (int i = 1; i <= N; ++i) {
		if (indegree[i] == 0) {
			pq.push(-i);
		}
	}

	while (!pq.empty()) {
		int cur = -pq.top();
		pq.pop();

		answer.push_back(cur);

		for (int next : graph[cur]) {
			--indegree[next];

			if (indegree[next] == 0) {
				pq.push(-next);
			}
		}
	}

	// 모든 원소를 방문하여 순서를 완벽하게 정한 경우
	if (answer.size() == N) {
		for (int i = 0; i < answer.size(); ++i) {
			cout << answer[i] << '\n';
		}
	}
	// 모든 원소를 방문하기 전에 queue가 비는 경우 : 사이클이 발생한 경우
	else {
		cout << "0" << '\n';
	}

	return;
}