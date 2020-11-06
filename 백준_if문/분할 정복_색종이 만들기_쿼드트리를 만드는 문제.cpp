#include <iostream>
using namespace std;

int arr[129][129];
int white = 0, blue = 0;
void divideAndConquer(int y, int x, int n);

int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> arr[i][j];
		}
	}
	divideAndConquer(1, 1, N);
	cout << white << '\n' << blue << '\n';
	return 0;
}
void divideAndConquer(int y, int x, int n) {
	int tmp = 0;
	for (int i = y; i < y + n; ++i) {
		for (int j = x; j < x + n; ++j) {
			if (arr[i][j] == 1)
				tmp++;
		}
	}
	if (tmp == 0)
		white++;
	else if (tmp == n * n)
		blue++;
	else {
		divideAndConquer(y, x, n / 2);
		divideAndConquer(y + n / 2, x, n / 2);
		divideAndConquer(y, x + n / 2, n / 2);
		divideAndConquer(y + n / 2, x + n / 2, n / 2);
	}
	return;
}