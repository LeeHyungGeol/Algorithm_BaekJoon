// bfs, MST ����

// �κ��� ������(S)���� ����Ͽ� �ٸ� ��� key��(K)�� ������ ����
// �κ��� ������ �����ϴ� �����Ƿ� ������ key��(K)�� ���� Node�� �ǰ�, ���ο� �������� �� �� �����Ƿ�, �׷����� �����Ѵ�.
// ���⼭ ���� ������(S)�� key��� �����ϰ� �����Ͽ���.
// ���⼭ �ִܰŸ��� ��� key���� �湮�ϴ� ���̹Ƿ�, ������ key�� ���� ���� �Ÿ��� �ִܰŸ��� ���ϰ�(bfs ���) (���⼭ �ð��� �����ɷȴ�.)
// ���� ������ ���� ������� MST(kruskal ���)�� �̿��Ͽ� ���� ���Ͽ���, 
// ���� ��� ������ �ϳ��� �ּ� ���� Ʈ���� �������� ������ -1 �� ����Ѵ�.

// �� bfs�� ����Ͽ��ĸ�, 
// ������ ���� ���(weight)�� ��� ���� ���¿��� �ִܰŸ��� ���ؾ� �Ͽ����Ƿ� bfs �� ����Ͽ���.

// �� MST�� ����Ͽ�����,
// ������ key�鿡�� �κ��� ������ �����Ͽ� �� ��忡�� �ٽ� ������ �����ϹǷ�, ������ key���� Node�� �ǰ�
// ������ Node�鿡�� �ٸ� ��� ������ ���� �ּ� �Ÿ��鸸 ��� Tree�� �����ؾ��ϹǷ�
// MST �� ����Ͽ���. 

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