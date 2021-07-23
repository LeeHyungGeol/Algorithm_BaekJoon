#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, char> pic;
typedef pair<int, int> pii;

int N, K, L, answer;
// 방향은 상관없이 일관성있게 한 방향으로 돌리면 된다.
// 서, 남, 동, 북
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
	// 시작은 무조건 오른쪽 방향
	int x = 0, y = 0, direction = 0;

	graph[x][y] = 2;
	q.push({ x, y });

	while (true) {
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		// 다음 칸이 뱀의 몸통이 아니고, 벽이 아닐 경우
		// 벽에 대한 조건을 먼저 쓰자!! 다음 칸이 존재하지 않는 칸일 수 있으므로 graph[nx][ny] 값을 읽어오지 못할 수 있다.
		if (0 <= nx && nx < N && 0 <= ny && ny < N && graph[nx][ny] != 2) {
			// 다음 칸이 사과일 경우
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = 2;
				q.push({ nx, ny });
			}
			// 사과가 아닐 경우
			else if (graph[nx][ny] != 1) {
				graph[nx][ny] = 2;
				q.push({ nx,ny });
				int a = q.front().first;
				int b = q.front().second;
				q.pop();
				graph[a][b] = 0;
			}
		}
		// 다음 칸이 뱀의 몸통 혹은 벽일 경우
		// 시간을 추가하고, 게임을 끝낸다.
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