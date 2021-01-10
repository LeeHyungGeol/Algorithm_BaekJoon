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
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v, e;//����� ����: v, ������ ����: e
int inDegree[100001] = { 0 };//��� ��忡 ���� ���� ������ 0���� �ʱ�ȭ
vector<int> graph[100001];
vector<int> topologicalSort() {
	vector<int> result;//�˰��� ���� ����� ���� ����Ʈ
	queue<int> q;//ť�� Ȱ���� ��������
	for (int i = 1; i <= v; ++i) {
		if (inDegree[i] == 0)//ó�� ������ �� ���� ������ 0�� ������ ť�� ����
			q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		result.push_back(cur);

		q.pop();
		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i];
			inDegree[next] -= 1;
			//inDegree[next]--;
			if (inDegree[next] == 0) {
				q.push(next);
			}
		}
	}
	return result;
}
int main() {
	cin >> v >> e;
	// ���� �׷����� ��� ���� ������ �Է� �ޱ�
	for (int i = 0; i < e; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); // ���� A���� B�� �̵� ����
		// ���� ������ 1 ����
		inDegree[b] += 1;
	}

	vector<int> ans = topologicalSort();

	// ���� ������ ������ ��� ���
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}
