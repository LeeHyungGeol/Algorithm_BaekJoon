#include <iostream>
#include <vector>

using namespace std;

typedef struct Node {
	int x, y, num;
}Node;

int N;
// ºÏ, µ¿, ³², ¼­
int Dx[] = { -1,0,1,0 };
int Dy[] = { 0,1,0,-1 };
vector<vector<int>> Arr;
Node Target;

void rotate();

int main() {
	cin >> N >> Target.num;

	Arr.resize(N, vector<int>(N, 0));

	rotate();

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << Arr[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << Target.x << ' ' << Target.y << '\n';

	return 0;
}

void rotate() {
	int x = N / 2, y = N / 2, cnt = 0, num = 0;
	Target.x = x + 1, Target.y = y + 1;
	Arr[x][y] = ++num;

	while (true) {
		for (int i = 0; i < 4; ++i) {
			if (i == 0 || i == 2) {
				++cnt;
			}
			for (int j = 0; j < cnt; ++j) {
				x += Dx[i];
				y += Dy[i];

				Arr[x][y] = ++num;

				if (num == Target.num) {
					Target.x = x+1;
					Target.y = y+1;
				}

				if (x == 0 && y == 0) {
					break;
				}
			}
			if (x == 0 && y == 0) {
				break;
			}
		}
		if (x == 0 && y == 0) {
			break;
		}
	}
}