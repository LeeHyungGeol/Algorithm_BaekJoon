//https://blog.naver.com/uss425/222181330549
//https://m.blog.naver.com/jqkt15/221935628641
//���� ���� ���(Strongly Connected Componensts): ���ϰ� ����� ���� ����
//���� SCC�� ���ϴ� �� ������ ���� ������ �����ϴ�.
//����Ŭ�� �߻��ϴ� ��� ������ SCC�� �ش��Ѵ�.
//���� �׷����� ���� �ǹ̰� �ִ�. ���� �׷������ �� �׷��� ��ü�� ������ SCC�̴�.
//�ڻ���� �˰���(Kosaraju's Algorithm), Ÿ�� �˰���(Tarjan's Algorithm)

//Ÿ�� �˰���(Tarjan's Algorithm): ��� ������ ���� DFS�� �����Ͽ� SCC�� ã�� �˰���
//1. DFS�� �����ϸ鼭 �θ� ���� Ȯ���Ѵ�. 
//2. Stack���� �ش� �θ� ���� ���� �� ���� ���Ҹ� �̾Ƴ���. 

//���� ���� ���(SCC)�� �� ��ü�δ� ū �ǹ̰� ������, ���� ����(Topological Sort)�� �Բ� ���� �� �ǹ̰� �� Ŀ����.
//""�� SCC ������ ����""���� �ϴ� ""��������""�� ���� �����ϴ�.
//���� ���� ��� �˰����� �ð� ���⵵�� O(V+E)�̴� : ��� ����(V)�� ���ؼ� DFS�� ����, ��� ����(E)�� ���ؼ� �ϳ��� Ȯ���Ѵ�.


//Ÿ�� �˰����� ���� �� �ϳ��� SCC�� ���� ������ �������� �����Ѵٴ� ��
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring> //memset
using namespace std;
#define MAX 500001

int T, N, M, S, P;
int id, pa[MAX];
bool finished[MAX];
vector<int> graph[MAX];
vector<vector<int>> SCC;
stack<int> s;
int inDegree[MAX];
int group[MAX];

int atm[MAX];
int finalCost[MAX];
vector<int> sccGraph[MAX];
bool Start[MAX];
bool End[MAX];

int dfs(int cur) {
	pa[cur] = ++id;
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
int topologicalSort() {
	queue<int> q;
	int result = 0;

	S = group[S];

	for (int i = 1; i <= SCC.size(); ++i) {
		finalCost[i] = atm[i];
		//if (group[S] == i) Start[i] = true;
		if (inDegree[i] == 0) q.push(i);
	}

	Start[S] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < sccGraph[cur].size(); ++i) {
			int next = sccGraph[cur][i];
			inDegree[next]--;
			if (Start[cur]) {
				finalCost[next] = max(finalCost[next], finalCost[cur] + atm[next]);
				Start[next] = true;
			}
			if (inDegree[next] == 0)
				q.push(next);
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (Start[i] && End[i]) result = max(result, finalCost[i]);
	}

	return result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N >> M;

	int from, to;
	for (int i = 0; i < M; ++i) {
		cin >> from >> to;
		graph[from].push_back(to);
	}

	for (int i = 1; i <= N; ++i)
		if (pa[i] == 0) dfs(i);

	int money;
	for (int i = 1; i <= N; ++i) {
		cin >> money;
		atm[group[i]] += money;
		for (int j = 0; j < graph[i].size(); ++j) {
			int next = graph[i][j];
			if (group[i] != group[next]) {
				inDegree[group[next]]++;
				sccGraph[group[i]].push_back(group[next]);
			}
		}
	}

	cin >> S >> P;

	int endPoint;
	for (int i = 0; i < P; ++i) {
		cin >> endPoint;
		End[group[endPoint]] = true;
	}

	cout << topologicalSort() << '\n';
	return 0;
}