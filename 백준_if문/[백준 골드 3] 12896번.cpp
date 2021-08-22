// 트리(트리의 지름), dfs 2번

// 트리의 지름 : 트리에서 거리가 가장 먼 정점간의 거리
// 임의의 시작점인 1번 노드를 기준으로 가장 먼 정점은 리프 노드 중 하나이다.

// 첫번째 리프 노드를 구하기 위해서, 임의의 노드인 1번 노드에서 dfs를 돌린다. 이때, 1번 노드에서 가장 먼 리프 노드 하나를 구한다.(maxIndex)
// 다시 한번, maxIndex에서 가장 먼 리프 노드를 구하기 위해서 maxIndex를 기준으로 dfs를 돌린다.
// 그리고 2번째 dfs에서 구해진 거리가 트리의 지름이 된다.

#include <iostream>
#include <vector>

using namespace std;

int N, Answer, maxIndex;
vector<vector<int>> Tree;
vector<bool> Visited;

void dfs(int cur, int curCost);

int main() {
	cin >> N;

	Tree.resize(N + 1);
	Visited.resize(N + 1, false);
	
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}

	dfs(1, 0);
	
	Visited.assign(N + 1, false);
	
	dfs(maxIndex, 0);
	
	cout << Answer - (Answer/2) << '\n';

	return 0;
}

void dfs(int cur, int curCost) {
	Visited[cur] = true;

	if (Answer < curCost) {
		Answer = curCost;
		maxIndex = cur;
	}

	for (int i = 0; i < Tree[cur].size(); ++i) {
		int next = Tree[cur][i];

		if (!Visited[next]) {
			dfs(next, curCost + 1);
		}
	}
}

