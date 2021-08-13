// 최단경로(플로이드 워셜) 문제

// 문제의 조건 중,  A와 B가 아닌 다른 파티장을 '경유'해서 더 빨리 갈 수 있는 경우가 있을 수 있다.
// 경유 하여 간다는 표현과 N의 최대 갯수가 500인 것을 보고 플로이드 워셜 알고리즘을 떠올릴 수 있었다.

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