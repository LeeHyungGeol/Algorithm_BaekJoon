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

		if (info == 1) {
			if (Indegree[building] == 0) {
				++Buildings[building];

				if (Buildings[building] == 1) {
					for (int next : Graph[building]) {
						--Indegree[next];
					}
				}
			}
			else {
				flag = false;
			}
		}
		else {
			if (Buildings[building] > 0) {
				--Buildings[building];
			}
			else {
				flag = false;
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
