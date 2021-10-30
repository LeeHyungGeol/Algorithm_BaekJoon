#include <iostream>
#include <vector>

using namespace std;

int N, Answer;
const int Dx[] = { 0,-1,0,1 };
const int Dy[] = { 1,0,-1,0 };
int Arr[101][101];

void makeDragonCurve(int x, int y, int d, int g);

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;
		Arr[x][y] = 1;
		int nx = x + Dx[d];
		int ny = y + Dy[d];
		Arr[nx][ny] = 1;
		makeDragonCurve(nx,ny,d,g);
	}

	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (Arr[i][j] && Arr[i+1][j] && Arr[i][j+1] && Arr[i+1][j+1]) {
				++Answer;
			}
		}
	}

	cout << Answer << '\n';

	return 0;
}

void makeDragonCurve(int x, int y, int d, int g) {
	vector<int> directions(1, d);

	for (int i = 0; i < g; ++i) {
		int size = directions.size();
		for (int j = size - 1; j >= 0; --j) {
			directions.push_back((directions[j] + 1) % 4);
		}
	}

	directions.erase(directions.begin());

	for (int d : directions) {
		int nx = x + Dx[d];
		int ny = y + Dy[d];

		Arr[nx][ny] = 1;

		x = nx, y = ny;
	}
}