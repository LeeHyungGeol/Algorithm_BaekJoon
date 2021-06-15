// ���ͽ�Ʈ�� �ִ� ��� ����
// (1, 1) ���� (N, M) ���� �̵��ϴµ� �ɸ��� �ִ� ����̸�, 
// �׶� ���� �μ� ���� �ּ� ������ ���ϴ� ����
// �� ������ �ٽ��� �ִ� ����̹Ƿ� �ѹ� �� ���� �ٽ� �ǵ��ư��� �ʴ� �Ϳ� �ִ�.
// �׷��Ƿ� ���ͽ�Ʈ�� �ִ� ��� �˰����� ����� �� �ִ�.
 
// �����ؾ��� ��
// N, M�� ���� ��, ���� �ƴ϶� ��, ���̶�� ��

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)

#define INF 1e9

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int N, M;
int graph[100][100] = { 0, };
int d[100][100] = { 0, };
bool visited[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dijkstra(int x, int y);

int main() {
	// N: ����ũ��, ��
	// M: ����ũ��, ��
	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%1d", &graph[i][j]);
			d[i][j] = INF;
		}
	}

	dijkstra(0, 0);

	cout << d[M - 1][N - 1] << '\n';
	
	return 0;
}

void dijkstra(int x, int y) {
	priority_queue<piii> pq;

	pq.push({ 0, { x, y } });
	d[x][y] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;

		pq.pop();

		if (visited[x][y]) {
			continue;
		}

		visited[x][y] = true;

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < M && 0 <= ny && ny < N) {
				if (dist + graph[nx][ny] < d[nx][ny]) {
					d[nx][ny] = dist + graph[nx][ny];
					pq.push({ -d[nx][ny], {nx, ny} });
				}
			}
		}
	}

	return;
}