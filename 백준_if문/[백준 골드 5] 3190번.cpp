#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int>  pii;

int N, K, L, X;
char C;
int arr[100][100] = { 0,};
// 동, 남, 서, 북
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
queue<pii> turnInfo;

int move(int x, int y);
int turn(int direction, char info);

int main() {
	cin >> N >> K;

	for (int i = 0; i < K; ++i) {
		int x, y;
		cin >> x >> y;
		arr[x - 1][y - 1] = 1;
	}

	cin >> L;

	for (int i = 0; i < L; ++i) {
		int time;
		char direction;
		cin >> time >> direction;
		turnInfo.push({ time, direction });
	}

	cout << move(0, 0) << '\n';

	return 0;
}

int move(int x, int y) {
	queue<pii> q;
	// 처음 위치 입력
	q.push({ x,y });
	arr[x][y] = 2;
	// 총 걸린 시간
	int time = 0;

	// 시작은 무조건 오른쪽 방향, 즉, 동쪽
	int direction = 0;

	while (true) {
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		// 다음 칸이 뱀의 몸통이 아니고, 벽이 아닐 경우
		if (arr[nx][ny] != 2 && 0 <= nx && nx < N && 0 <= ny && ny < N) {
			
			// 다음 칸이 사과일 경우
			if (arr[nx][ny] == 1) {
				arr[nx][ny] = 2;
				q.push({ nx, ny });
			}
			// 사과가 아닐 경우
			else {
				arr[nx][ny] = 2;
				q.push({ nx, ny });
				int a = q.front().first;
				int b = q.front().second;
				arr[a][b] = 0;
				q.pop();
			}
		}
		// 다음 칸이 뱀의 몸통 혹은 벽일 경우
		// 시간을 추가하고, 게임을 끝낸다.
		else {
			++time;
			break;
		}

		++time;
		x = nx;
		y = ny;

		if (!turnInfo.empty() && time == turnInfo.front().first) {
			direction = turn(direction, turnInfo.front().second);
			turnInfo.pop();
		}
	}

	return time;
}

int turn(int direction, char info) {
	if (info == 'L') {
		return (direction == 0) ? 3 : direction - 1;
	}
	else {
		return (direction == 3) ? 0 : direction + 1;
	}
}