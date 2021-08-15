// dfs ����, ��� ���ϱ�(Tree���� �ڽ��� ����)

// ����� ���� ���� �������İ� dfs Ȥ�� bfs�� ��������!!

// Tree�� ���� �������� �����⿡���� �ڽ��� ����
// ������ Tree���� �ڽ��� ������ X�� ����� ���� �� �ִ�.

// ���������� �ȵǴ� ������ 
// ���� Ʈ���� ���� �������� ���� �ڽİ� ������ �ڽİ��� �쿭�� Ȯ���ϰ� ���� �� ���� ������
// �� ���������� ���� ������ ������ �� ����.

#include <iostream>
#include <vector>

using namespace std;

int N, M, X;
vector<vector<int>> Tree[2];
vector<bool> Visited;

int dfs(int cur, int type);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X;

	Tree[0].resize(N + 1);
	Tree[1].resize(N + 1);
	Visited.resize(N + 1, false);

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		Tree[0][b].push_back(a);
		Tree[1][a].push_back(b);
	}

	// �ּ� �� ��
	// X���� ���� �� ���� �ִ��� Ȯ��
	// -> �Է°� ����, ������ Ʈ������ X �������� X�� �ڽĵ��� ������� Ȯ�� 
	int first = dfs(X, 0);
	
	Visited.assign(N + 1, false);

	// �ִ� �� ��
	// X���� �ؿ� �� ���� �ִ��� Ȯ��
	// -> �Է°� ����, ������ Ʈ������ X �������� X�� �ڽĵ��� ��� �ִ��� Ȯ��
	// �׸��� ��ü(N)���� X�� �ڽĵ��� �A ������ 1��(�ڱ��ڽ�)�� ���� ���� ���Ѵ�.
	int second = N - dfs(X, 1) + 1;

	cout << first << ' ' << second << '\n';

	return 0;
}

int dfs(int cur, int type) {
	int nodes = 1;
	Visited[cur] = true;

	for (int next : Tree[type][cur]) {
		if (!Visited[next]) {
			nodes += dfs(next, type);
		}
	}

	return nodes;
}