#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX 5001

int k, n;
int id, scc, pa[MAX * 2], group[MAX * 2], ans[MAX];
bool finished[MAX * 2];
vector<int> graph[MAX * 2];
stack<int> s;
inline int oppo(int n, char c) { return (c == 'R') ? n + 1 : n - 1; }
int dfs(int cur) {
	int parent = pa[cur] = ++id;
	s.push(cur);

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (pa[next] == 0) parent = min(parent, dfs(next));
		else if (!finished[next]) parent = min(parent, pa[next]);
	}

	if (parent == pa[cur]) {
		while (1) {
			int t = s.top();
			s.pop();
			group[t] = scc;
			finished[t] = true;
			if (t == cur) break;
		}
		scc++;
	}
	return parent;
}

int main() {
	cin >> k >> n;

	int v;
	char c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> v >> c;
			//R: Âü: È¦¼ö, B: °ÅÁþ: Â¦¼ö


		}
	}

	return 0;
}