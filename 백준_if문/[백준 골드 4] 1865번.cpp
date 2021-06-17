// 최단거리(벨만포드) 문제
// 벨만포드 알고리즘: 음의 간선이 존재할 때 적용할 수 있는 최단거리 알고리즘

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int TC, N, M, W;
int d[501] = { 0, };
vector<piii> graph;

int main() {
	cin >> TC >> N >> M >> W;

	for (int tc = 0; tc < TC; ++tc) {
		graph.clear();
		
		for (int i = 0; i < M; ++i) {
			int S, E, T;
			cin >> S >> E >> T;
			graph.push_back({ S, {E, T} });
		}
		
		for (int i = 0; i < W; ++i) {
			int S, E, T;
			cin >> S >> E >> T;
			graph.push_back({ S, {E, T} });
		}


	
	}

	return 0;
}