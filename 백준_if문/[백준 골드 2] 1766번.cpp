//���� ����(Topological Sort): '����Ŭ�� ���� ���� �׷���'�� '��� ��带 ���⼺�� �Ž����� �ʵ��� ������� ����'�ϴ� ���� �ǹ�
//����Ŭ�� ���� ���� �׷���: DAG(Directed Acyclic Graph)
//��������(Indegree): Ư���� ���� ������ ������ ����
//��������(Outdegree): Ư���� ��忡�� ������ ������ ����
//Stack�� Ȱ���� DFS�� Ǯ�ų� Queue�� ��������(Topological Sort)�� Ǯ �� �ִ�.

//���� ����(Topological Sort)�� DAG�� ���ؼ��� ������ �����ϴ�.
//'��� ���Ҹ� �湮�ϱ� ���� ť�� ��ٸ� '����Ŭ�� �����Ѵٰ� �Ǵ�'�� �� �ִ�.
//���� ���� �˰����� �ð� ���⵵: O(V+E) : ���ʴ�� ��� ��带 Ȯ���ϸ� �� ��忡�� ������ ������ ���ʴ�� �����ؾ� �Ѵ�.

//�ܼ��� queue�� �ƴ� '�켱���� ť(priority_queue)'�� �̿��Ѵ�.

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