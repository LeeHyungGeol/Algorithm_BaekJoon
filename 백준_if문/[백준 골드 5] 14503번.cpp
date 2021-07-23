// ����, �ù����̼� ����
// ������_���� ���� ������ �Ȱ���. 
// 1. ��, ��, ��, �� �� 4���� ����, 2. ������ �״�� ���鼭 ��ĭ �����ϴ� ���, 
// 3. ������ ��ĭ����, 4. û���ߴ��� ���ߴ���(�湮�ߴ��� ���ߴ���)
// �̷��� ���׵��� �����س� �� �ִ��� ����� ����

// ���߿� �� �ٽ� �ѹ� Ǯ� ��!!

#include <iostream>
#include <vector>

using namespace std;

int N, M, x, y, direction, cnt, answer;
// ��, ��, ��, ��
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<vector<int>> graph;
vector<vector<bool>> visited;

void turnLeft();

int main() {
	cin >> N >> M;

	cin >> x >> y >> direction;

	graph.resize(N, vector<int>(M));
	visited.resize(N, vector<bool>(M));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> graph[i][j];
		}
	}

	visited[x][y] = true;
	++answer;

	while (true) {
		turnLeft();

		int nx = x + dx[direction];
		int ny = y + dy[direction];
		
		if (0 <= nx && nx < N && 0 <= ny && ny < M) {
			if (!visited[nx][ny] && graph[nx][ny] != 1) {
				visited[nx][ny] = true;
				x = nx;
				y = ny;
				cnt = 0;
				++answer;
				continue;
			}
			else if(graph[nx][ny] == 1) {
				++cnt;
			}
			else if (visited[nx][ny]) {
				++cnt;
			}
		}

		if (cnt == 4) {
			nx = x - dx[direction];
			ny = y - dy[direction];

			if (graph[nx][ny] == 0) {
				x = nx;
				y = ny;
			}
			else {
				break;
			}

			cnt = 0;
		}
	}

	cout << answer << '\n';

	return 0;
}

void turnLeft() {
	--direction;

	if (direction == -1) {
		direction = 3;
	}

	return;
}