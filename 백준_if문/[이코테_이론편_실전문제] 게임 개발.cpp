#include <iostream>

using namespace std;

// 0: 북쪽
// 1: 동쪽
// 2: 남쪽
// 3: 서쪽

int N, M, x, y, direction, answer;
int arr[50][50] = { 0, };
bool visited[51][51];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void turnLeft();

int main() {
	cin >> N >> M;

	cin >> x >> y >> direction;

	visited[x][y] = true;
	++answer;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0;

	while (true) {
		turnLeft();
		
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		if (!visited[nx][ny] && arr[nx][ny] == 0) {
			visited[nx][ny] = true;
			x = nx;
			y = ny;
			cnt = 0;
			++answer;
			continue;
		}
		else {
			++cnt;
		}

		if (cnt == 4) {
			// 뒤로 이동 // 바라보는방향 그대로 뒤로 이동이기 때문에 -를 붙인다.
			nx = x - dx[direction];
			ny = y - dy[direction];

			// 뒤로 이동이 가능한 경우
			if (arr[nx][ny] == 0) {
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
