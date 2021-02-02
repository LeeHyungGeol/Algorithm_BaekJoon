//전체 명제를 참으로 만드는 케이스는 함의 그래프에서 위상정렬을 해서, 각 정점을 false 로 만들어서 손해 볼 것이 없다는 개념으로
//정점이 이미 true / false 가 정해졌다면 넘어가고, 안정해져있다면 not 정점이면 true, 아니면 false 로 변수들을 하나씩 true / false 를 정하면서 나간다.
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 5001
typedef pair<int, int> pii;
int k, n;// k and n (3 < k ≤ 5,000, 1 ≤ n ≤ 10,000)
int id, scc, pa[MAX * 2], group[MAX * 2], ans[MAX];
bool finished[MAX * 2];
vector<int> graph[MAX * 2];
stack<int> s;
inline int oppo(int n) { return (n % 2) ? n + 1 : n - 1; }
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
	int tmp[3];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> v >> c;
			//R: 참: 홀수, B: 거짓: 짝수
			tmp[j] = (c == 'R') ? v * 2 - 1 : v * 2;
		}
		graph[oppo(tmp[0])].push_back(tmp[1]);//~a->b
		graph[oppo(tmp[1])].push_back(tmp[0]);//~b->a
		graph[oppo(tmp[1])].push_back(tmp[2]);
		graph[oppo(tmp[2])].push_back(tmp[1]);
		graph[oppo(tmp[0])].push_back(tmp[2]);
		graph[oppo(tmp[2])].push_back(tmp[0]);
	}

	for (int i = 1; i <= 2 * k; ++i) {
		if (pa[i] == 0) dfs(i);
	}
	bool flag = true;
	for (int i = 1; i <= k; ++i) {
		if (group[i * 2 - 1] == group[i * 2]) {
			flag = false; break;
		}
	}
	if (!flag) {
		cout << "-1" << '\n';
	}
	else {
		memset(ans, -1, sizeof(ans));
		vector<pii> TSorder;
		for (int i = 1; i <= 2 * k; ++i)
			TSorder.push_back({ group[i], i });

		sort(TSorder.begin(), TSorder.end(), greater<pii>());

		for (auto p : TSorder) {//정점이 홀수(참)이었다면, 거짓(0)으로 설정, 짝수(거짓)이었다면, ~(~p)인 참으로 설정해준다.
			int vertex = p.second;
			if (ans[(vertex + 1) / 2] == -1)//아직 값이 갱신 안된 상태
				ans[(vertex + 1) / 2] = (vertex % 2) ? 0 : 1;//1 : x1, 2 : ~x1
		}

		for (int i = 1; i <= k; ++i) {
			(ans[i]) ? cout << "R" : cout << "B";
		}
		cout << '\n';
	}
	return 0;
}