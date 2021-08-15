// 위상정렬, 구현 문제

// 정확하게 위상정렬 문제는 아니지만, 방향 그래프에서 순서가 있게 node들을 정렬 시키는 개념을 활용하는 문제였다.

// 위상정렬(topologicalSort)에서의 Indegree[](진입차수)의 개념을 다시 한번 정확하게 짚어보는 좋은 문제였다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M, K;
vector<int> Indegree;
vector<int> Buildings;
vector<vector<int>> Graph;

void topologicalSort();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> K;

	Buildings.resize(N + 1, 0);
	Indegree.resize(N + 1, 0);
	Graph.resize(N + 1);

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		Graph[a].push_back(b);
		++Indegree[b];
	}

	topologicalSort();

	return 0;
}

void topologicalSort() {
	bool flag = true;

	for (int i = 0; i < K; ++i) {
		int info, building;
		cin >> info >> building;

		// 건물을 건설할 때
		if (info == 1) {
			// 현재 건물의 진입차수가 0이 아니다 == 현재 건물의 앞에 있는 건물을 짓지 않았다.
			if (Indegree[building] != 0) {
				flag = false;
				break;
			}
			else {
				++Buildings[building];

				// 지어진 건물 개수가 1개일 때만 next의 진입차수 갯수를 낮춰준다.
				// 건물이 여러개 지어질 수도 있기 때문에, 1개일 때만 처리해준다.
				if (Buildings[building] == 1) {
					for (int next : Graph[building]) {
						--Indegree[next];
					}
				}
			}
		}
		else {
			// 지어진 건물 갯수가 0개일 경우, 건물을 파괴할 수 있는 갯수가 없는 것이므로, 거짓
			if (Buildings[building] == 0) {
				flag = false;
				break;
			}
			else {
				--Buildings[building];

				// 지어진 건물 갯수가 0개일 경우, next의 진입차수도 그에 맞춰 다시 올려준다.
				// 현재 지어진 건물 갯수가 0이므로, 다음에 지어질 건물도 못 짓도록 만들어줘야 한다.
				// (Indegree[next]가 양수이면 next의 건물을 지을 수 없다는 의미)
				if (Buildings[building] == 0) {
					for (int next : Graph[building]) {
						++Indegree[next];
					}
				}
			}
		}
	}

	if (flag) {
		cout << "King-God-Emperor" << '\n';
	}
	else {
		cout << "Lier!" << '\n';
	}

	return;
}
