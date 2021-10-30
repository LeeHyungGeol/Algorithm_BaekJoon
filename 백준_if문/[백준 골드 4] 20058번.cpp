#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int N, Q, iceSum;
const int Dx[] = { -1,1,0,0 };
const int Dy[] = { 0,0,-1,1 };
int Arr[70][70];
int TempArr[70][70];
bool CheckMelt[70][70];
bool Visited[70][70];

void fireStorm(int L);
void check(int x, int y);
int getBiggestComponents();
int dfs(int x, int y);
void rotate(int x, int y, int n);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;

	N = 1 << N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> Arr[i][j];
		}
	}

	for (int i = 0; i < Q; ++i) {
		int L;
		cin >> L;
		L = 1 << L;
		fireStorm(L);
	}
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (Arr[i][j] > 0) iceSum += Arr[i][j];
		}
	}

	int result = getBiggestComponents();

	cout << iceSum << '\n' << result << '\n';

	return 0;
}

void fireStorm(int L) {
	memset(CheckMelt, false, sizeof(CheckMelt));
	memset(TempArr, 0, sizeof(TempArr));

	for (int x = 0; x < N; x += L) {
		for (int y = 0; y < N; y += L) {
			rotate(x, y, L);
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			check(i, j);
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (CheckMelt[i][j]) --Arr[i][j];
		}
	}
}

void check(int x, int y) {
	int cnt = 0;

	for (int i = 0; i < 4; ++i) {
		int nx = x + Dx[i];
		int ny = y + Dy[i];

		if (!(0 <= nx && nx < N && 0 <= ny && ny < N)) continue;
		if (Arr[nx][ny] <= 0) continue;
		++cnt;
	}
	if (cnt < 3) CheckMelt[x][y] = true;
}

int getBiggestComponents() {
	memset(Visited, false, sizeof(Visited));
	int nodes = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!Visited[i][j] && Arr[i][j] > 0) {
				nodes = max(nodes, dfs(i, j));
			}
		}
	}

	return nodes;
}

int dfs(int x, int y) {
	Visited[x][y] = true;
	int nodes = 1;

	for (int i = 0; i < 4; ++i) {
		int nx = x + Dx[i];
		int ny = y + Dy[i];

		if (!(0 <= nx && nx < N && 0 <= ny && ny < N)) continue;
		if (Visited[nx][ny]) continue;
		if (Arr[nx][ny] <= 0) continue;
		nodes += dfs(nx, ny);
	}

	return nodes;
}

void rotate(int x, int y, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			TempArr[j][n - i - 1] = Arr[x + i][y+j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			Arr[x+i][y+j] = TempArr[i][j];
		}
	}
}