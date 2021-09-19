// º°Âï±â, ±¸Çö, Àç±Í ¹®Á¦

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> Arr;

void recursive(int n, int x, int y);

int main() {
	cin >> N;
	Arr.resize(4 * N - 3, vector<char>(4 * N - 3, ' '));

	recursive(N, 0, 0);

	for (int i = 0; i < 4 * N - 3; ++i) {
		for (int j = 0; j < 4 * N - 3; ++j) {
			cout << Arr[i][j];
		}
		cout << '\n';
	}

	return 0;
}

void recursive(int n, int x, int y) {
	if (n == 1) {
		Arr[x][y] = '*';
		return;
	}

	int length = 4 * n - 3;

	for (int j = y; j < y + length; ++j) {
		Arr[x][j] = '*';
		Arr[x + length - 1][j] = '*';
	}

	for (int i = x; i < x + length; ++i) {
		Arr[i][y] = '*';
		Arr[i][y + length - 1] = '*';
	}

	recursive(n - 1, x + 2, y + 2);
	return;
}