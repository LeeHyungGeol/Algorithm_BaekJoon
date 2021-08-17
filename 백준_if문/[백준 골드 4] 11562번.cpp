// �ִܰŸ�(�÷��̵� ����) ����

// �÷��̵� ���� ������ �׻� ��� �������� �ٸ� ��� ���������� `����` 
// ��, ����Ǿ� �ֳ�, ����Ǿ� ���� �ʳ� / �� �� �ֳ�, ������ ������ ���´�.

// �� �������� ��¦ ���Ƽ�, Graph[a][b]�� ���� 0�̸� �� �� �ִٴ� �ǹ��̴�.
// Graph[a][b] = 0 : a���� b�� �� �� �ִٶ�� �ǹ�
// �Է��� ���� ��, 
// b�� 0 �̸�(�ܹ���), Graph[u][v] = 0 ���� �Է�(u���� v�� �� �� �����Ƿ�)
// Graph[v][u] �� 1 �̴�. �ܹ����� ��������� �ٲ�� �ϹǷ� 1 �� �Է�

// b�� 1 �̸�(�����), Graph[u][v] = 0, Graph[v][u] = 0, ���ʿ� ������̹Ƿ� �� �� �� �� �ֱ� �����̴�. 

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

int N, M, K;
vector<vector<int>> Graph;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	Graph.resize(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == j) {
				Graph[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < M; ++i) {
		int u, v, b;
		cin >> u >> v >> b;
		Graph[u][v] = 0;
		Graph[v][u] = (b == 0) ? 1 : 0;
	}

	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
			}
		}
	}

	cin >> K;

	for (int i = 0; i < K; ++i) {
		int s, e;
		cin >> s >> e;
		cout << Graph[s][e] << '\n';
	}

	return 0;
}