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
#include <cstring> //memset
using namespace std;
#define MAX 100001

int T, N, M;
int idx, pa[100001];
bool finished[100001];
vector<int> graph[100001];
vector<vector<int>> SCC;
stack<int> s;
int inDegree[100001];
int group[100001];

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
			scc.push_back(t);
			finished[t] = true;
			group[t] = SCC.size() + 1;
			if (t == cur) break;
		}
		SCC.push_back(scc);
	}

	return parent;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; ++t) {
		memset(pa, 0, sizeof(pa));
		memset(finished, false, sizeof(finished));
		memset(inDegree, 0, sizeof(inDegree));
		memset(group, 0, sizeof(group));
		SCC.clear();

		cin >> N >> M;

		for (int i = 1; i <= N; ++i)
			graph[i].clear();

		int from, to;
		for (int i = 0; i < M; ++i) {
			cin >> from >> to;
			graph[from].push_back(to);
		}

		for (int i = 1; i <= N; ++i)
			if (pa[i] == 0) dfs(i);

		for (int i = 1; i <= N; ++i) {
			for (int j = 0; j < graph[i].size(); ++j) {
				int next = graph[i][j];
				if (group[i] != group[next]) inDegree[group[next]]++;
			}
		}

		int answer = 0;
		for (int i = 0; i < SCC.size(); ++i)
			if (inDegree[i] == 0) answer++;
		cout << answer << '\n';
	}
	return 0;
}