#include <iostream>

using namespace std;

// 0: ����
// 1: ����
// 2: ����
// 3: ����

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
			// �ڷ� �̵� // �ٶ󺸴¹��� �״�� �ڷ� �̵��̱� ������ -�� ���δ�.
			nx = x - dx[direction];
			ny = y - dy[direction];

			// �ڷ� �̵��� ������ ���
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
