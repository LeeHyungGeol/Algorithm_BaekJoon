#include <iostream>
using namespace std;

int main() {

	int T, H, W, N, x = 1, y = 1;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		y = N % H;
		x = N / H;
		if (y == 0)
			y = H;
		else
			x++;
		cout << (100 * y) + x << '\n';
	}

	return 0;
}