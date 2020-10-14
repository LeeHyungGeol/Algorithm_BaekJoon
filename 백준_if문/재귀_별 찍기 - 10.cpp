#include <iostream>
using namespace std;

void star(int n, int x, int y);
char arr[6562][6562];
int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			arr[i][j] = ' ';
		}
	}

	star(N, N, N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;
}
void star(int n, int x, int y) {
	
	if (n == 3) { //정사각형 별 그리기
		arr[y][x] = '*';
		arr[y][x - 1] = '*';
		arr[y][x - 2] = '*';

		arr[y - 1][x] = '*';
		arr[y - 1][x - 2] = '*';

		arr[y - 2][x] = '*';
		arr[y - 2][x - 1] = '*';
		arr[y - 2][x - 2] = '*';
	}
	else {
		star(n / 3, x, y);
		star(n / 3, x - n / 3, y);
		star(n / 3, x - n / 3 - n / 3, y);

		star(n / 3, x, y - n / 3);
		star(n / 3, x - n / 3 - n / 3, y - n / 3);

		star(n / 3, x, y - n / 3 - n / 3);
		star(n / 3, x - n / 3, y - n / 3 - n / 3);
		star(n / 3, x - n / 3 - n / 3, y - n / 3 - n / 3);
	}
}