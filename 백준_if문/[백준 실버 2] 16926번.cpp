#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
// ³², µ¿, ºÏ, ÁÂ
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
vector<vector<int>> Arr;

void rotate(vector<vector<int>>& arr);
int turn(int startX, int startY, int endX, int endY, int x, int y, int dir);

int main() {
	cin >> N >> M >> R;

	Arr.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> Arr[i][j];
		}
	}

	while (R--) {
		rotate(Arr);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << Arr[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}

void rotate(vector<vector<int>>& arr) {
	int x = 0, y = 0, dir = 0, swapTemp = 0;
	int startX = 0, startY = 0, endX = arr.size() - 1, endY = arr[0].size() - 1;
	int count = min(N, M) / 2;

	while (count--) {
		swapTemp = arr[startX][startY];
		x = startX, y = startY, dir = 0;

		while (true) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			int temp = arr[nx][ny];
			swap(swapTemp, arr[nx][ny]);
			swapTemp = temp;

			x = nx;
			y = ny;

			dir = turn(startX, startY, endX, endY, x, y, dir);

			if (x == startX && y == startY) {
				break;
			}
		}
		++startX;
		++startY;
		--endX;
		--endY;
	}
	return;
}

int turn(int startX, int startY, int endX, int endY, int x, int y, int dir) {
	if (x == endX && y == startY) {
		dir = 1;
	}
	else if (x == endX && y == endY) {
		return 2;
	}
	else if (x == startX && y == endY) {
		return 3;
	}
	return dir;
}