#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> indegree;
vector<int> graph[1001];

int main() {
	cin >> N >> M;

	indegree.resize(N + 1, 0);

	int temp;

	for (int i = 0; i < M; ++i) {
		cin >> temp;
		for (int j = 0; j < temp; ++j) {
			
		}
	}

	return 0;
}