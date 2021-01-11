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
//""��� ���Ҹ� �湮�ϱ� ����"" ť�� ��ٸ� """����Ŭ�� �����Ѵٰ� �Ǵ�"""�� �� �ִ�.
//���������� 0�� �ƴ� 1�̻��� ��尡 �߻��ϱ� �����̴�.
//���� ���� �˰����� �ð� ���⵵: O(V+E) : ���ʴ�� ��� ��带 Ȯ���ϸ� �� ��忡�� ������ ������ ���ʴ�� �����ؾ� �Ѵ�.
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int T, n, m;// �׽�Ʈ ���̽��� 100���� ���� �ʴ´�.  (2 �� n �� 500),  (0 �� m �� 25000)
int inDegree[501] = { 0 };
bool graph[501][501];
void topologicalSort() {
	vector<int> ans;
	queue<int> q;
	bool certain = true;

	for (int i = 1; i <= n; ++i) {
		if (inDegree[i] == 0)
			q.push(i);
	}
	//��� ���Ҹ� �湮�Ѵ�. 
	while (!q.empty()) {//for(int i = 0; i < n; ++i)���ε� ��ü ����
		if (q.size() >= 2) {//���� ������ 0�� ��尡 2�� �̻��� ���
			certain = false;//Ȯ���� ������ ã�� �� ����.
			break;
		}

		int cur = q.front();
		ans.push_back(cur);

		q.pop();
		for (int i = 1; i <= n; ++i) {
			if (graph[cur][i]) {
				inDegree[i]--;
				if (inDegree[i] == 0)
					q.push(i);
			}
		}
	}

	if (!certain)
		cout << "?" << '\n';
	else if (ans.size() == n) {//���� ������ ������ ���� ���
		for (int i = 0; i < n; ++i)//vector�� size�� ����� ������ ����.
			cout << ans[i] << ' ';
		cout << '\n';
	}
	else {//�����Ϳ� �ϰ����� ��� ������ ���� �� ���� ���
		//��� ���Ҹ� �湮�ϱ� ���� queue�� ��� ��� : ����Ŭ�� �߻��� ���
		cout << "IMPOSSIBLE" << '\n';
	}
}
int main() {
	cin >> T;
	for (int t = 0; t < T; ++t) {
		memset(inDegree, 0, sizeof(inDegree));
		memset(graph, false, sizeof(graph));

		cin >> n;

		vector<int> rank(n);
		for (int i = 0; i < n; ++i)
			cin >> rank[i];

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				graph[rank[i]][rank[j]] = true;
				inDegree[rank[j]]++;
			}
		}

		cin >> m;
		int a, b;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			if (graph[a][b]) {
				graph[a][b] = false;
				graph[b][a] = true;
				inDegree[b]--;
				inDegree[a]++;
			}
			else {
				graph[a][b] = true;
				graph[b][a] = false;
				inDegree[b]++;
				inDegree[a]--;
			}
		}

		topologicalSort();
	}
	return 0;
}