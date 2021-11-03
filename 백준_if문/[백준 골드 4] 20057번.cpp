#include <iostream>
#include <vector>

using namespace std;

int N, Answer;
// ¼­, ³², µ¿, ºÏ
const int Dx[] = {0,1,0,-1};
const int Dy[] = {-1,0,1,0};
const int dx[4][10] = { { -1,-1,-1,1,1,1,2,-2,0,0 }, { 1,0,-1,1,0,-1,0,0,2,1 }, { -1,-1,-1,1,1,1,2,-2,0,0} , { -1,0,1,-1,0,1,0,0,-2,-1} };
const int dy[4][10] = { { -1,0,1,-1,0,1,0,0,-2,-1 }, { -1,-1,-1,1,1,1,2,-2,0,0 } , { 1,0,-1,1,0,-1,0,0,2,1} , { -1,-1,-1,1,1,1,-2,2,0,0} };
const int rate[] = { 10,7,1,10,7,1,2,2,5,75 };
vector<vector<int>> Arr;

void rotate();
void tornado(int x, int y, int dir);

int main() {
	cin >> N;

	Arr.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> Arr[i][j];
		}
	}

	rotate();

	cout << Answer << '\n';

	return 0;
}

void rotate() {
	int x = N / 2, y = N / 2, cnt = 0;

	while (true) {
		for (int i = 0; i < 4; ++i) {
			if (i == 0 || i == 2) ++cnt;
			for (int j = 0; j < cnt; ++j) {
				x += Dx[i];
				y += Dy[i];

				tornado(x, y, i);

				if (x == 0 && y == 0) {
					tornado(x, y, i);
					break;
				}
			}
			if (x == 0 && y == 0) break;
		}
		if (x == 0 && y == 0) break;
	}
}

void tornado(int x, int y, int dir) {
	if (Arr[x][y] == 0) return;

	int totalSand = Arr[x][y];
	int temp = totalSand;

	for (int i = 0; i < 9; ++i) {
		int nx = x + dx[dir][i];
		int ny = y + dy[dir][i];
		int sand = (temp * rate[i]) / 100;

		if (!(0 <= nx && nx < N && 0 <= ny && ny < N)) Answer += sand;
		else Arr[nx][ny] += sand;

		totalSand -= sand;
	}

	int nx = x + dx[dir][9];
	int ny = y + dy[dir][9];

	if (!(0 <= nx && nx < N && 0 <= ny && ny < N)) Answer += totalSand;
	else Arr[nx][ny] += totalSand;

	Arr[x][y] = 0;
}