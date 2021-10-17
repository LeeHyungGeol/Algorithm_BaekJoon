#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct Coord {
	int x, y;
}Coord;

int N, M, Answer, Marble[4];
// ¼­, ³², µ¿, ºÏ
int initX[] = { 0,1,0,-1 };
int initY[] = { -1,0,1,0 };
// ºÏ, ³², ¼­, µ¿
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };
Coord Shark;
vector<bool> Deleted;
vector<Coord> Coords;
vector<vector<int>> Arr;
vector<vector<int>> NumberArr;

void print();
void initArr();
void blizzard(int dir, int distance);
void moveMarble();
bool destroyMarble();
void remakeArr();

int main() {
	cin >> N >> M;

	Arr.assign(N, vector<int>(N, 0));
	NumberArr.assign(N, vector<int>(N, 0));
	Coords.assign(N*N+1, { 0,0 });
	Deleted.assign(N*N+1, false);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> Arr[i][j];
		}
	}
	
	initArr();

	for (int i = 0; i < M; ++i) {
		int dir, distance;
		cin >> dir >> distance;

		blizzard(dir, distance);
		moveMarble();

		while (destroyMarble()) {
			moveMarble();
		}

		remakeArr();
	}

	Answer = Marble[1] + (2 * Marble[2]) + (3 * Marble[3]);

	cout << Answer << '\n';

	return 0;
}

void print() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << Arr[i][j] << ' ';
		}
		cout << '\n';
	}
	return;
}

void initArr() {
	int x = N / 2, y = N / 2, cnt = 0, num = 0;
	Shark = { x,y };
	Coords[num] = { x,y };
	NumberArr[x][y] = num;
	int limits = 0;

	while (true) {
		for (int i = 0; i < 4; ++i) {
			if (i == 0 || i == 2) {
				++cnt;
			}
			for (int j = 0; j < cnt; ++j) {
				x += initX[i];
				y += initY[i];
				NumberArr[x][y] = ++num;
				Coords[num] = { x,y };
				++limits;

				if (limits==N*N-1) {
					break;
				}
			}
			if (limits == N * N - 1) {
				break;
			}
		}
		if (limits == N * N - 1) {
			break;
		}
	}

	return;
}

void blizzard(int dir, int distance) {
	Deleted.assign(N*N+1, false);

	int x = Shark.x, y = Shark.y;

	for (int i = 0; i < distance; ++i) {
		x += dx[dir];
		y += dy[dir];
		Deleted[NumberArr[x][y]] = true;
	}
}

void moveMarble() {
	bool flag = false;
	int cnt = 0;

	for (int n = 1; n < N * N; ++n) {
		if (Deleted[n]) {
			++cnt;
			flag = true;
		}
		else {
			if (Arr[Coords[n].x][Coords[n].y] == 0) {
				for (int i = 1; i <= cnt; ++i) {
					Arr[Coords[n - i].x][Coords[n - i].y] = 0;
				}
				flag = false;
				break;
			}
			else {
				Arr[Coords[n - cnt].x][Coords[n - cnt].y] = Arr[Coords[n].x][Coords[n].y];
			}
		}
	}

	if (flag) {
		int n = (N * N) - 1;
		for (int j = 0; j < cnt; ++j, --n) {
			Arr[Coords[n].x][Coords[n].y] = 0;
		}
	}

	return;
}

bool destroyMarble() {
	Deleted.assign(N*N+1, false);

	bool flag = false;
	int cur = Arr[Coords[1].x][Coords[1].y], cnt = 1, start = 1;
	int n;

	for (n = 2; n < N * N; ++n) {
		int next = Arr[Coords[n].x][Coords[n].y];

		if (next == 0) {
			break;
		}

		if (cur == next) {
			++cnt;
		}
		else {
			if (cnt >= 4) {
				for (int i = start; i < n; ++i) {
					Deleted[i] = true;
				}
				Marble[cur] += cnt;
				flag = true;
			}

			cur = next;
			cnt = 1;
			start = n;
		}
	}

	if (cnt >= 4) {
		for (int i = start; i < n; ++i) {
			Deleted[i] = true;
		}
		Marble[cur] += cnt;
		flag = true;
	}

	return flag;
}

void remakeArr() {	
	vector<vector<int>> temp(N, vector<int>(N, 0));
	int cur = Arr[Coords[1].x][Coords[1].y], cnt = 1, pos = 1;
	bool flag = true;

	for (int n = 2; n < N * N; ++n) {
		if (pos >= N * N) {
			flag = false;
			break;
		}

		int next = Arr[Coords[n].x][Coords[n].y];
		
		if (next == 0) {
			break;
		}
		if (cur == next) {
			++cnt;
		}
		else {
			temp[Coords[pos].x][Coords[pos].y] = cnt;
			temp[Coords[pos+1].x][Coords[pos+1].y] = cur;
			cur = next;
			pos += 2;
			cnt = 1;
		}
	}

	if (flag && pos != 1) {
		temp[Coords[pos].x][Coords[pos].y] = cnt;
		temp[Coords[pos + 1].x][Coords[pos + 1].y] = cur;
	}

	Arr = temp;
	
	return;
}