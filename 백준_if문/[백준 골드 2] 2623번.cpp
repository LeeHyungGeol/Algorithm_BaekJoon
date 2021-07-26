// ��������(topological sort) ����
// �켱���� ť(priority_queue), ť(queue)�� ����, �� �������� �ƹ� ����� ����.
// ����Ŭ(cycle)�� �߻��� ��� == ��� ���Ҹ� �湮�ϱ� ���� queue�� ��� == vector.size() != N(��� ����� ����) �̴�.

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

	// ��� ���Ҹ� �湮�Ͽ� ������ �Ϻ��ϰ� ���� ���
	if (answer.size() == N) {
		for (int i = 0; i < answer.size(); ++i) {
			cout << answer[i] << '\n';
		}
	}
	// ��� ���Ҹ� �湮�ϱ� ���� queue�� ��� ��� : ����Ŭ�� �߻��� ���
	else {
		cout << "0" << '\n';
	}

	return;
}