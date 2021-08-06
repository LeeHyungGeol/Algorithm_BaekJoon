//������ ����ġ�� ���⼺�� ���� ������ ��Ʈ �ִ� Ʈ���� �־����� ��, �Ʒ��� ������ ���غ����� ����.
//���� U�� ��Ʈ�� �ϴ� ����Ʈ���� ���� ������ ���� ����Ѵ�.
//->dfs Ȥ�� bfs�� �캸��
//Ʈ���� �θ� ã�� ����(11725��)�� ���� �Ϲ����� dfs, bfs�� ������ Ʋ����.
//��Ʈ�� ��ȣ R�� ���� ���� Ȱ������.
//dp������ ���� ��԰� �־���. �޸������̼��� ����.

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