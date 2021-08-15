// dfs 문제, 등수 구하기(Tree에서 자식의 갯수)

// 등수를 구할 때는 위상정렬과 dfs 혹은 bfs도 생각하자!!

// Tree와 같은 구조에서 정방향에서의 자식의 갯수
// 역방향 Tree에서 자식의 갯수로 X의 등수를 구할 수 있다.

// 위상정렬이 안되는 이유는 
// 이진 트리와 같은 구조에서 왼쪽 자식과 오른쪽 자식간의 우열을 확실하게 가릴 수 없기 때문에
// 이 문제에서는 위상 정렬을 적용할 수 없다.

#include <iostream>
#include <vector>

using namespace std;

int N, M, X;
vector<vector<int>> Tree[2];
vector<bool> Visited;

int dfs(int cur, int type);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X;

	Tree[0].resize(N + 1);
	Tree[1].resize(N + 1);
	Visited.resize(N + 1, false);

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		Tree[0][b].push_back(a);
		Tree[1][a].push_back(b);
	}

	// 최소 몇 등
	// X보다 위에 몇 명이 있는지 확인
	// -> 입력값 기준, 역방향 트리에서 X 기준으로 X의 자식들이 몇명인지 확인 
	int first = dfs(X, 0);
	
	Visited.assign(N + 1, false);

	// 최대 몇 등
	// X보다 밑에 몇 명이 있는지 확인
	// -> 입력값 기준, 정방향 트리에서 X 기준으로 X의 자식들이 몇명 있는지 확인
	// 그리고 전체(N)에서 X의 자식들을 뺸 값에서 1개(자기자신)을 더한 값을 구한다.
	int second = N - dfs(X, 1) + 1;

	cout << first << ' ' << second << '\n';

	return 0;
}

int dfs(int cur, int type) {
	int nodes = 1;
	Visited[cur] = true;

	for (int next : Tree[type][cur]) {
		if (!Visited[next]) {
			nodes += dfs(next, type);
		}
	}

	return nodes;
}