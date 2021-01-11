//���� ����(Topological Sort): """"����Ŭ�� ���� ���� �׷���"""�� """��� ��带 ���⼺�� �Ž����� �ʵ��� ������� ����"""�ϴ� ���� �ǹ�
//����Ŭ�� ���� ���� �׷���: DAG(Directed Acyclic Graph)
//��������(Indegree): Ư���� ���� ������ ������ ����
//��������(Outdegree): Ư���� ��忡�� ������ ������ ����
//Stack�� Ȱ���� DFS�� Ǯ�ų� Queue�� ��������(Topological Sort)�� Ǯ �� �ִ�.
//ť�� �̿��� ���� ���� �˰����� ���� ����: 1. ���������� 0�� ��� ��带 ť�� �ִ´�.
//											  2. ť�� �� ������ ������ ������ �ݺ��Ѵ�.
//											     2-1) ť���� ���Ҹ� ���� �ش� ��忡�� ������ ������ �׷������� �����Ѵ�.
//												 2-2) ���Ӱ� ���������� 0�� �� ��带 ť�� �ִ´�.
//			��������� """�� ��尡 ť�� ���� ������ ���� ������ ������ ���"""�� ����.

//���� ����(Topological Sort)�� DAG�� ���ؼ��� ������ �����ϴ�.
//""��� ���Ҹ� �湮�ϱ� ���� ť�� ��ٸ� """����Ŭ�� �����Ѵٰ� �Ǵ�"""�� �� �ִ�.
//���� ���� �˰����� �ð� ���⵵: O(V+E) : ���ʴ�� ��� ��带 Ȯ���ϸ� �� ��忡�� ������ ������ ���ʴ�� �����ؾ� �Ѵ�.


//�ܼ��� queue�� �ƴ� ""�켱���� ť(priority_queue)""�� �̿��Ѵ�.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;//N(1 �� N �� 32,000), M(1 �� M �� 100,000)
int inDegree[32001] = { 0 };
vector<int> graph[32001];
void topologicalSort() {
	vector<int> result;
	priority_queue<int> pq;

	for (int i = 1; i <= N; ++i) {
		if (inDegree[i] == 0)
			pq.push(-i);//�ּ� ���̾�� �ϱ� ������ - �� �ٿ��ش�.
	}

	while (!pq.empty()) {
		int cur = -pq.top();//�ּ� ���̾�� �ϱ� ������ - �� �ٿ��ش�.
		result.push_back(cur);

		pq.pop();
		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i];
			inDegree[next]--;
			if (inDegree[next] == 0)
				pq.push(-next);//�ּ� ���̾�� �ϱ� ������ - �� �ٿ��ش�.
		}
	}

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << ' ';
	cout << '\n';
}
int main() {
	cin >> N >> M;
	int from, to;
	for (int i = 0; i < M; ++i) {
		cin >> from >> to;
		graph[from].push_back(to);
		inDegree[to]++;
	}

	topologicalSort();
	return 0;
}