#include <iostream>
#include <vector>

using namespace std;

int N, M, X, Y;
// ºÏ, µ¿, ³², ÁÂ
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<vector<int>> Arr;

void rotate();

int main() {
	cin >> N >> M;
	
	Arr.resize(N+1, vector<int>(N+1, 0));

	rotate();

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cout << Arr[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << X << ' ' << Y << '\n';

	return 0;
}

void rotate() {
	int x = N / 2 + 1, y = N / 2 + 1, cnt = 0, num = 0;
	X = N / 2 + 1, Y = N / 2 + 1;
	Arr[x][y] = ++num;

	while (true) {
		for (int i = 0; i < 4; ++i) {
			if (i == 0 || i == 2) {
				++cnt;
			}
			for (int j = 0; j < cnt; ++j) {
				x += dx[i];
				y += dy[i];

				Arr[x][y] = ++num;

				if (num == M) {
					X = x, Y = y;
				}
				if (x == 1 && y == 1) {
					break;
				}
			}
			if (x == 1 && y == 1) {
				break;
			}
		}
		if (x == 1 && y == 1) {
			break;
		}
	}

	return;
}