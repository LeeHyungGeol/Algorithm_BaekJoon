#include <iostream>
#define RIGHT 1
#define DOWN 2
#define RIGHTDOWN 3
#define LEFTDOWN 4

using namespace std;

int Arr[21][21];

bool check(int x, int y, int color);
bool isMiddle(int x, int y, int color, int dir);
bool inRange(int x, int y);

int main() {
	for (int i = 1; i < 20; ++i) {
		for (int j = 1; j < 20; ++j) {
			cin >> Arr[i][j];
		}
	}

	bool flag = false;

	for (int i = 1; i < 20; ++i) {
		for (int j = 1; j < 20; ++j) {
			if (Arr[i][j] == 0) continue;
			if (check(i, j, Arr[i][j])) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	if (!flag) {
		cout << "0" << '\n';
	}

	return 0;
}

bool check(int x, int y, int color) {
	int cnt = 0;
	int nx = x, ny = y;
	if (!isMiddle(x, y, color, DOWN)) {
		while (true) {
			if (!(1 <= nx && nx < 20 && 1 <= ny && ny < 20)) break;
			if (Arr[nx][ny] == color) ++cnt;
			else break;
			++nx;
		}
	}

	if (cnt == 5) {
		cout << Arr[x][y] << '\n' << x << " " << y << '\n';
		return true;
	}

	cnt = 0, nx = x, ny = y;
	if (!isMiddle(x, y, color, RIGHT)) {
		while (true) {
			if (!(1 <= nx && nx < 20 && 1 <= ny && ny < 20)) break;
			if (Arr[nx][ny] == color) ++cnt;
			else break;
			++ny;
		}
	}

	if (cnt == 5) {
		cout << Arr[x][y] << '\n' << x << " " << y << '\n';
		return true;
	}

	cnt = 0, nx = x, ny = y;
	if (!isMiddle(x, y, color, RIGHTDOWN)) {
		while (true) {
			if (!(1 <= nx && nx < 20 && 1 <= ny && ny < 20)) break;
			if (Arr[nx][ny] == color) ++cnt;
			else break;
			++ny;
			++nx;
		}
	}

	if (cnt == 5) {
		cout << Arr[x][y] << '\n' << x << " " << y << '\n';
		return true;
	}

	cnt = 0, nx = x, ny = y;
	if (!isMiddle(x, y, color, LEFTDOWN)) {
		while (true) {
			if (!(1 <= nx && nx < 20 && 1 <= ny && ny < 20)) break;
			if (Arr[nx][ny] == color) ++cnt;
			else break;
			--ny;
			++nx;
		}
	}

	if (cnt == 5) {
		--nx; ++ny;
		cout << Arr[nx][ny] << '\n' << nx << " " << ny << '\n';
		return true;
	}

	return false;
}

bool isMiddle(int x, int y, int color, int dir) {
	if (dir == RIGHT && inRange(x,y-1) && Arr[x][y - 1] == color) return true;
	else if (dir == DOWN && inRange(x-1,y) && Arr[x - 1][y] == color) return true;
	else if (dir == RIGHTDOWN && inRange(x-1,y-1) && Arr[x - 1][y - 1] == color) return true;
	else if (dir == LEFTDOWN && inRange(x-1,y+1) && Arr[x - 1][y + 1] == color) return true;
	return false;
}

bool inRange(int x, int y) {
	return (1 <= x && x < 20 && 1 <= y && y < 20);
}