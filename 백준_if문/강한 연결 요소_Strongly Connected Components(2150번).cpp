//���� ���� ���(Strongly Connected Componensts): ���ϰ� ����� ���� ����
//���� SCC�� ���ϴ� �� ������ ���� ������ �����ϴ�.
//����Ŭ�� �߻��ϴ� ��� ������ SCC�� �ش��Ѵ�.
//���� �׷����� ���� �ǹ̰� �ִ�. ���� �׷������ �� �׷��� ��ü�� ������ SCC�̴�.
//�ڻ���� �˰���(Kosaraju's Algorithm), Ÿ�� �˰���(Tarjan's Algorithm)

//Ÿ�� �˰���(Tarjan's Algorithm): ��� ������ ���� DFS�� �����Ͽ� SCC�� ã�� �˰���
//1. DFS�� �����ϸ鼭 �θ� ���� Ȯ���Ѵ�. 
//2. Stack���� �ش� �θ� ���� ���� �� ���� ���Ҹ� �̾Ƴ���. 

//Ÿ�� �˰����� ���� �� �ϳ��� SCC�� ���� ������ �������� �����Ѵٴ� ��
//���� ���� ���(SCC)�� �� ��ü�δ� ū �ǹ̰� ������, ���� ����(Topological Sort)�� �Բ� ���� �� �ǹ̰� �� Ŀ����.
//""�� SCC ������ ����""���� �ϴ� ""��������""�� ���� �����ϴ�.
//���� ���� ��� �˰����� �ð� ���⵵�� O(V+E)�̴� : ��� ������ ���ؼ� DFS�� ����, ��� ������ ���ؼ� �ϳ��� Ȯ���Ѵ�.

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX 10001

int V, E;//V(1 �� V �� 10,000), E(1 �� E �� 100,000)
int idx, pa[MAX];
bool finished[MAX];
vector<int> graph[MAX];
vector<vector<int>> SCC;
stack<int> s;

int dfs(int cur) {
	pa[cur] = ++idx;
	s.push(cur);
	int parent = pa[cur];

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (pa[next] == 0) parent = min(parent, dfs(next));
		else if (!finished[next]) parent = min(parent, pa[next]);
	}

	if (parent == pa[cur]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			finished[t] = true;
			scc.push_back(t);
			if (t == cur) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}

	return parent;
}
int main() {
	cin >> V >> E;
	int from, to;
	for (int i = 0; i < E; ++i) {
		cin >> from >> to;
		graph[from].push_back(to);
	}

	for (int i = 1; i <= V; ++i)
		if (pa[i] == 0) dfs(i);

	sort(SCC.begin(), SCC.end());

	cout << SCC.size() << '\n';
	for (int i = 0; i < SCC.size(); ++i) {
		for (int j = 0; j < SCC[i].size(); ++j) {
			cout << SCC[i][j] << ' ';
		}
		cout << "-1\n";
	}
	return 0;
}