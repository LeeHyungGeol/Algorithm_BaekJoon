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
//���������� 0�� �ƴ� 1�̻��� ��尡 �߻��ϱ� �����̴�.
//���� ���� �˰����� �ð� ���⵵: O(V+E) : ���ʴ�� ��� ��带 Ȯ���ϸ� �� ��忡�� ������ ������ ���ʴ�� �����ؾ� �Ѵ�.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;//N(1��N��32,000), M(1��M��100,000)
int inDegree[32001] = { 0 };
vector<int> graph[32001];
vector<int> topologicalSort() {
	vector<int> result;
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (inDegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		result.push_back(cur);

		q.pop();
		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i];
			inDegree[next] -= 1;
			if (inDegree[next] == 0)
				q.push(next);
		}
	}
	return result;
}
int main() {
	cin >> N >> M;
	int from, to;
	for (int i = 0; i < M; ++i) {
		cin >> from >> to;
		graph[from].push_back(to);//from���� to�� �̵� ����
		inDegree[to]+=1;//���������� 1 ����
	}
	vector<int> ans = topologicalSort();

	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}