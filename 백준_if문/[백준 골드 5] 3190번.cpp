#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, char> pic;
typedef pair<int, int> pii;

int N, K, L, answer;
// ������ ������� �ϰ����ְ� �� �������� ������ �ȴ�.
// ��, ��, ��, ��
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
vector<vector<int>> graph;
queue<pic> info;
queue<pii> q;

void snakeMove();
int turn(int direction, char turnInfo);

int main() {
	cin >> N >> K;

	graph.resize(N, vector<int>(N, 0));

	for (int i = 0; i < K; ++i) {
		int x, y;
		cin >> x >> y;
		graph[x - 1][y - 1] = 1;
	}

	cin >> L;

	for (int i = 0; i < L; ++i) {
		int time;
		char direction;
		cin >> time >> direction;
		info.push({ time, direction });
	}

	snakeMove();

	cout << answer << '\n';

	return 0;
}

void snakeMove() {
	// ������ ������ ������ ����
	int x = 0, y = 0, direction = 0;

	graph[x][y] = 2;
	q.push({ x, y });

	while (true) {
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		// ���� ĭ�� ���� ������ �ƴϰ�, ���� �ƴ� ���
		// ���� ���� ������ ���� ����!! ���� ĭ�� �������� �ʴ� ĭ�� �� �����Ƿ� graph[nx][ny] ���� �о���� ���� �� �ִ�.
		if (0 <= nx && nx < N && 0 <= ny && ny < N && graph[nx][ny] != 2) {
			// ���� ĭ�� ����� ���
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = 2;
				q.push({ nx, ny });
			}
			// ����� �ƴ� ���
			else if (graph[nx][ny] != 1) {
				graph[nx][ny] = 2;
				q.push({ nx,ny });
				int a = q.front().first;
				int b = q.front().second;
				q.pop();
				graph[a][b] = 0;
			}
		}
		// ���� ĭ�� ���� ���� Ȥ�� ���� ���
		// �ð��� �߰��ϰ�, ������ ������.
		else {
			++answer;
			break;
		}

		++answer;
		x = nx;
		y = ny;

		if (!info.empty() && answer == info.front().first) {
			direction = turn(direction, info.front().second);
			info.pop();
		}
	}

	return;
}

int turn(int direction, char turnInfo) {
	if (turnInfo == 'L') {
		return (direction == 3) ? 0 : direction + 1;
	}
	else {
		return (direction == 0) ? 3 : direction - 1;
	}
}