// �ִܰŸ�(�÷��̵� ����) ����
// �ִ� �Ÿ��� ���� ��, ���İ��� '�ִ� ���'�� �Բ� ����ϴ� ���� ����

// Route[i][j] = k; -> ���� i���� ���� j�� �ּ� ������� �� ��, ���İ��� ������ k

// findRoute(start, end) -> (start, k), (k, end)
// k �� 2�� ���� �ǹǷ� �߰��� Route.pop_back() ����
// Route[start][end] == 0 : ���̻� ���İ� ���� k�� ���ٴ� �ǹ�, '����� ���� ����'

// Graph[i][j] == 0 : i,j �� ������ ���
// Graph[i][j] == INF : i���� j�� ���� �� �� ����.

// [����] https://yabmoons.tistory.com/441

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

int N, M;
vector<vector<int>> Graph;
vector<vector<int>> Routes;
vector<int> Route;

void findRoute(int start, int end);

int main() {
	cin >> N >> M;

	Graph.resize(N + 1, vector<int>(N + 1, INF));
	Routes.resize(N + 1, vector<int>(N + 1, 0));

	for (int i = 0; i < M; ++i) {
		int a, b, cost;
		cin >> a >> b >> cost;
		Graph[a][b] = min(Graph[a][b], cost);
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == j) {
				Graph[i][j] = 0;
			}
		}
	}

	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (Graph[i][j] > Graph[i][k] + Graph[k][j]) {
					Graph[i][j] = Graph[i][k] + Graph[k][j];
					// ���� i���� ���� j�� �ּ� ������� �� ��, ���İ��� ������ k
					Routes[i][j] = k;
				}
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (Graph[i][j] == INF) {
				cout << "0" << ' ';
			}
			else {
				cout << Graph[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			Route.clear();

			// Graph[i][j] == 0 : i,j �� ������ ���
			// Graph[i][j] == INF : i���� j�� ���� �� �� ����.
			if (Graph[i][j] == 0 ||Graph[i][j] == INF) {
				cout << "0" << '\n';
			}
			else {
				findRoute(i, j);
				cout << Route.size() << ' ';

				for (int i = 0; i < Route.size(); ++i) {
					cout << Route[i] << ' ';
				}
				cout << '\n';
			}
		}
	}

	return 0;
}

// (start, end) -> (start, k), (k, end)
// k �� 2�� ���� �ǹǷ� �߰��� Route.pop_back() ����
// Route[start][end] == 0 : ���̻� ���İ� ���� k�� ���ٴ� �ǹ�, '����� ���� ����'
void findRoute(int start, int end) {
	if (Routes[start][end] == 0) {
		Route.push_back(start);
		Route.push_back(end);
		return;
	}

	findRoute(start, Routes[start][end]);
	Route.pop_back();
	findRoute(Routes[start][end], end);
}