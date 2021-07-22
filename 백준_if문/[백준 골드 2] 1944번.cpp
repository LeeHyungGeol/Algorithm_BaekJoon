// bfs, MST 문제

// 로봇이 시작점(S)에서 출발하여 다른 모든 key들(K)을 모으는 문제
// 로봇이 복제가 가능하다 했으므로 각각의 key들(K)이 전부 Node가 되고, 새로운 시작점이 될 수 있으므로, 그래프를 형성한다.
// 여기서 나는 시작점(S)도 key라고 변경하고 시작하였다.
// 여기서 최단거리로 모든 key들을 방문하는 것이므로, 각각의 key들 까지 가는 거리의 최단거리를 구하고(bfs 사용) (여기서 시간이 오래걸렸다.)
// 구한 간선에 대한 정보들로 MST(kruskal 사용)를 이용하여 답을 구하였고, 
// 만약 모든 노드들이 하나의 최소 신장 트리에 속해있지 않으면 -1 을 출력한다.

// 왜 bfs를 사용하였냐면, 
// 간선에 대한 비용(weight)이 모두 같은 상태에서 최단거리를 구해야 하였으므로 bfs 를 사용하였다.

// 왜 MST를 사용하였나면,
// 각각의 key들에서 로봇이 복제가 가능하여 그 노드에서 다시 시작이 가능하므로, 각각의 key들이 Node가 되고
// 각각의 Node들에서 다른 모든 노드까지 가는 최소 거리들만 골라서 Tree를 형성해야하므로
// MST 를 사용하였다. 

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int N, M, nodeNum = 0, answer;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<int> parent;
vector<vector<char>> graph;
vector<vector<int>> keyNum;
vector<vector<bool>> visited;
vector<pii> nodes;
vector<piii> edges;

void getAllDistance(int x, int y, int start);
void kruskal();
int findParent(int x);
void unionParent(int a, int b);

int main() {
	cin >> N >> M;

	graph.resize(N, vector<char>(N));
	keyNum.resize(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> graph[i][j];
			if (graph[i][j] == 'S') {
				graph[i][j] = 'K';
			}

			if (graph[i][j] == 'K') {
				nodes.push_back({ i,j });
				keyNum[i][j] = ++nodeNum;
			}
		}
	}

	for (int i = 0; i < nodes.size(); ++i) {
		getAllDistance(nodes[i].first, nodes[i].second, i+1);
	}
	
	kruskal();

	cout << answer << '\n';

	return 0;
}

void getAllDistance(int x, int y, int start) {
	visited.assign(N, vector<bool>(N, false));
	queue<pii> q;
	
	q.push({ x, y });
	visited[x][y] = true;

	int dist = 1;

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; ++i) {
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; ++j) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (0 <= nx && nx < N && 0 <= ny && ny < N) {
					if (!visited[nx][ny] && graph[nx][ny] != '1') {
						visited[nx][ny] = true;
						q.push({ nx,ny });

						if (graph[nx][ny] == 'K') {
							edges.push_back({ dist, { start, keyNum[nx][ny] }});
						}
					}
				}
			}
		}

		++dist;
	}

	return;
}

void kruskal() {
	parent.resize(nodeNum + 1);

	for (int i = 1; i <= nodeNum; ++i) {
		parent[i] = i;
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); ++i) {
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		int cost = edges[i].first;

		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			answer += cost;
		}
	}

	int p = parent[1];

	for (int i = 2; i <= nodeNum; ++i) {
		if (p != parent[i]) {
			answer = -1;
		}
	}

	return;
}

int findParent(int x) {
	if (parent[x] != x) {
		parent[x] = findParent(parent[x]);
	}
	return parent[x];
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}