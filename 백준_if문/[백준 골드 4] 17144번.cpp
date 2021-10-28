#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef struct Node {
	int x, y;
}Node;

int R, C, T, Answer;
const int Dx[] = { -1,1,0,0 };
const int Dy[] = { 0,0,-1,1 };
vector<vector<int>> Arr;
vector<vector<int>> TempArr;
vector<Node> AirConditioner;
vector<Node> Dusts;

void findDusts();
void diffusion();
void cleanAir();
void cleanUp();
void cleanDown();
int clockWise(int x, int y, int dir);
int counterClockWise(int x, int y, int dir);

void input() {
	cin >> R >> C >> T;

	Arr.assign(R, vector<int>(C, 0));

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> Arr[i][j];
			if (Arr[i][j] == -1) {
				Arr[i][j] = 0;
				AirConditioner.push_back({ i,j });
			}
		}
	}
}
int main() {
	input();

	while (T--) {
		findDusts();
		diffusion();
		cleanAir();
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (Arr[i][j] > 0) Answer += Arr[i][j];
		}
	}

	cout << Answer << '\n';

	return 0;
}

void findDusts() {
	Dusts.clear();

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (Arr[i][j] > 0) Dusts.push_back({ i,j });
		}
	}
}

void diffusion() {
	TempArr = Arr;

	for (Node dust : Dusts) {
		int cnt = 0;
		int value = Arr[dust.x][dust.y] / 5;

		for (int i = 0; i < 4; ++i) {
			int nx = dust.x + Dx[i];
			int ny = dust.y + Dy[i];

			if (!(0 <= nx && nx < R && 0 <= ny && ny < C)) continue;
			if (nx == AirConditioner[0].x && ny == AirConditioner[0].y) continue;
			if (nx == AirConditioner[1].x && ny == AirConditioner[1].y) continue;
			++cnt;
			TempArr[nx][ny] += value;
		}
		TempArr[dust.x][dust.y] = TempArr[dust.x][dust.y] - (value * cnt);
	}

	Arr = TempArr;
}

void cleanAir() {
	cleanUp();
	cleanDown();
}

void cleanUp() {
	// µ¿, ºÏ, ¼­, ³²
	int dx[] = {0,-1,0,1};
	int dy[] = {1,0,-1,0};
	int x = AirConditioner[0].x, y = AirConditioner[0].y;
	int cur = 0, dir = 0;

	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		int after = Arr[nx][ny];
		Arr[nx][ny] = cur;
		swap(after, cur);

		x = nx, y = ny;

		dir = clockWise(x,y,dir);

		if (x == AirConditioner[0].x && y == AirConditioner[0].y) {
			Arr[x][y] = 0;
			break;
		}
	}
}

int clockWise(int x, int y, int dir) {
	if (x == AirConditioner[0].x && y == C-1) return 1;
	if (x == 0 && y == C-1) return 2;
	if (x == 0 && y == 0) return 3;
	return dir;
}

void cleanDown() {
	// µ¿, ³², ¼­, ºÏ
	int dx[] = { 0,1,0,-1 };
	int dy[] = { 1,0,-1,0 };
	int x = AirConditioner[1].x, y = AirConditioner[1].y;
	int cur = 0, dir = 0;

	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		int after = Arr[nx][ny];
		Arr[nx][ny] = cur;
		swap(after, cur);

		x = nx, y = ny;

		dir = counterClockWise(x, y, dir);

		if (x == AirConditioner[1].x && y == AirConditioner[1].y) {
			Arr[x][y] = 0;
			break;
		}
	}
}

int counterClockWise(int x, int y, int dir) {
	if (x == AirConditioner[1].x && y == C-1) return 1;
	if (x == R-1 && y == C-1) return 2;
	if (x == R-1 && y == AirConditioner[1].y) return 3;
	return dir;
}

