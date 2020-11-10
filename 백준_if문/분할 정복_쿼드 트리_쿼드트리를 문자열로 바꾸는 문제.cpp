#include <iostream>
#include <string>
using namespace std;
char arr[65][65];
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
	cout << '\n';

	return 0;
}
void divideAndConquer(int y, int x, int n) {
	int tmp = 0;
	for (int i = y; i < y + n; ++i) {
		for (int j = x; j < x + n; ++j) {
			if (arr[i][j] == '1')
				tmp++;
		}
	}
	if (tmp == 0) {
		cout << '0';
	}
	else if (tmp == n * n) {
		cout << '1';
	}
	else {
		cout << '(';
		divideAndConquer(y, x, n / 2);
		divideAndConquer(y, x + n / 2, n / 2);
		divideAndConquer(y + n / 2, x, n / 2);
		divideAndConquer(y + n / 2, x + n / 2, n / 2);
		cout << ')';
	}
	return;
}