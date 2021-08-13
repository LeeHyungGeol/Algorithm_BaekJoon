// �ִܰ��(�÷��̵� ����) ����

// ������ ���� ��,  A�� B�� �ƴ� �ٸ� ��Ƽ���� '����'�ؼ� �� ���� �� �� �ִ� ��찡 ���� �� �ִ�.
// ���� �Ͽ� ���ٴ� ǥ���� N�� �ִ� ������ 500�� ���� ���� �÷��̵� ���� �˰����� ���ø� �� �־���.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, M;
vector<vector<ll>> Graph;

void floyd_warshall();

int main() {
	cin >> N >> M;

	Graph.resize(N + 1, vector<ll>(N + 1, 0));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> Graph[i][j];
		}
	}

	floyd_warshall();

	for (int i = 0; i < M; ++i) {
		ll a, b, c;

		cin >> a >> b >> c;
		if (Graph[a][b] <= c) {
			cout << "Enjoy other party" << '\n';
		}
		else {
			cout << "Stay here" << '\n';
		}
	}

	return 0;
}

void floyd_warshall() {
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
			}
		}
	}
	return;
}