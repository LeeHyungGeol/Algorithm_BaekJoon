#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, D;
vector<vector<int>> Arr;

void rotate(int deg);
void clockwise();
void counterclockwise();

int main() {
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> N >> D;

		Arr.assign(N + 1, vector<int>(N + 1, 0));
		
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> Arr[i][j];
			}
		}

		rotate(D);

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				cout << Arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}

void rotate(int deg) {
	int time = 0;

	if (deg > 0) {
		time = (deg / 45) % 8;

		for (int t = 0; t < time; ++t) {
			clockwise();
		}
	}
	else {
		deg = abs(deg);
		time = (deg / 45) % 8;

		for (int t = 0; t < time; ++t) {
			counterclockwise();
		}
	}
}

void clockwise() {
	vector<vector<int>> temp = Arr;
	
	for(int i = 0; i < N; ++i) {
		temp[1+i][N-i] = Arr[1+i][(N+1)/2];
	}

	for (int i = 0; i < N; ++i) {
		temp[(N+1)/2][N-i] = Arr[1 + i][N - i];
	}

	for (int i = 0; i < N; ++i) {
		temp[N-i][N-i] = Arr[(N + 1) / 2][N - i];
	}

	for (int i = 0; i < N; ++i) {
		temp[N-i][(N+1)/2] = Arr[N - i][N - i];
	}

	Arr = temp;
}

void counterclockwise() {
	vector<vector<int>> temp = Arr;

	for (int i = 1; i <= N; ++i) {
		temp[(N+1)/2][i] = Arr[i][i];
	}

	for (int i = 0; i < N; ++i) {
		temp[N-i][1+i] = Arr[(N + 1) / 2][i+1];
	}

	for (int i = 0; i < N; ++i) {
		temp[N-i][(N+1)/2] = Arr[N-i][1+i];
	}

	for (int i = 0; i < N; ++i) {
		temp[N-i][N-i] = Arr[N - i][(N + 1) / 2];
	}

	Arr = temp;
}
