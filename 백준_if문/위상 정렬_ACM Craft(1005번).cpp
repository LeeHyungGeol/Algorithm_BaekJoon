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
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring> //memset
using namespace std;
int T, N, K, W;//2 �� N �� 1000, 1 �� K �� 100, 000
int time[1001] = { 0 };
int inDegree[1001] = { 0 };
vector<int> graph[1001];
void topologicalSort() {
	vector<int> result(N + 1);
	queue<int> q;

	for (int i = 1; i <= N; ++i) {
		result[i] = time[i];
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		
		q.pop();
		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i];
			result[next] = max(result[next], result[cur] + time[next]);
			inDegree[next]--;
			if (inDegree[next] == 0)
				q.push(next);
		}
	}
	cout << result[W] << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; ++t) {
		memset(time, 0, sizeof(time));
		memset(graph, 0, sizeof(graph));
		memset(inDegree, 0, sizeof(inDegree)); 

		cin >> N >> K;
		for (int i = 1; i <= N; ++i)
			cin >> time[i];
		int from, to;
		for (int i = 1; i <= K; ++i) {
			cin >> from >> to;
			graph[from].push_back(to);
			inDegree[to]++;
		}
		cin >> W;
		topologicalSort();
	}

	return 0;
}