#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> Arr;

void printStars(int x, int y, int n);

int main() {
	cin >> N;

	Arr.assign(4*N-3, vector<char>(4*N-3, ' '));
	
	printStars(0,0,N);

	for (int i = 0; i < 4 * N - 3; ++i) {
		for (int j = 0; j < 4 * N - 3; ++j) {
			cout << Arr[i][j];
		}
		cout << '\n';
	}

	return 0;
}

void printStars(int x, int y, int n) {
	if (n == 1) {
		Arr[x][y] = '*';
		return;
	}

	int size = 4 * n - 3;

	for (int i = x; i < x+size; ++i) {
		Arr[i][y] = '*';
		Arr[i][y + size - 1] = '*';
	}

	for (int i = y; i < y+size; ++i) {
		Arr[x][i] = '*';
		Arr[x + size - 1][i] = '*';
	}

	printStars(x + 2, y + 2, n - 1);
}