// 최단거리(플로이드 워셜) 문제
// 최단 거리로 갔을 때, 거쳐가는 '최단 경로'도 함께 출력하는 좋은 문제

// Route[i][j] = k; -> 정점 i에서 정점 j로 최소 비용으로 갈 때, 거쳐가는 정점은 k

// findRoute(start, end) -> (start, k), (k, end)
// k 가 2번 들어가게 되므로 중간에 Route.pop_back() 실행
// Route[start][end] == 0 : 더이상 거쳐갈 정점 k가 없다는 의미, '재귀의 기저 조건'

// Graph[i][j] == 0 : i,j 가 동일한 노드
// Graph[i][j] == INF : i에서 j로 도달 할 수 없다.

// [참고] https://yabmoons.tistory.com/441

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
					// 정점 i에서 정점 j로 최소 비용으로 갈 때, 거쳐가는 정점은 k
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

			// Graph[i][j] == 0 : i,j 가 동일한 노드
			// Graph[i][j] == INF : i에서 j로 도달 할 수 없다.
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
// k 가 2번 들어가게 되므로 중간에 Route.pop_back() 실행
// Route[start][end] == 0 : 더이상 거쳐갈 정점 k가 없다는 의미, '재귀의 기저 조건'
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