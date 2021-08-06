//간선에 가중치와 방향성이 없는 임의의 루트 있는 트리가 주어졌을 때, 아래의 쿼리에 답해보도록 하자.
//정점 U를 루트로 하는 서브트리에 속한 정점의 수를 출력한다.
//->dfs 혹은 bfs로 헤보자
//트리의 부모 찾기 문제(11725번)과 같이 일반적인 dfs, bfs로 돌리면 틀린다.
//루트의 번호 R에 대한 것을 활용하자.
//dp문제인 것을 까먹고 있었다. 메모이제이션을 하자.

#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
vector<bool> Visited;
vector<int> Dp;
vector<vector<int>> Tree;

int dfs(int cur);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> R >> Q;

	Tree.resize(N + 1);
	Dp.resize(N + 1, -1);
	Visited.resize(N + 1, false);

	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}

	dfs(R);

	for (int i = 0; i < Q; ++i) {
		int q;
		cin >> q;
		cout << Dp[q] << '\n';
	}

	return 0;
}

int dfs(int cur) {
	int& ret = Dp[cur];

	if (ret != -1) {
		return ret;
	}

	ret = 1;
	Visited[cur] = true;

	for (int next : Tree[cur]) {
		if (!Visited[next]) {
			ret += dfs(next);
		}
	}

	return ret;
}