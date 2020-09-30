#include <iostream>
using namespace std;

int main() {

	int X, x = 0, y = 0, cnt = 1;
	cin >> X;
	while (cnt < X) {
		X -= cnt;
		cnt++;
	}
	if (cnt % 2 == 0) {
		for (int i = cnt; i > 0; i--) {
			y = i;
			x++;
			X--;
			if (X == 0)
				break;
		}
	}
	else {
		for (int i = cnt; i > 0; i--) {
			x = i;
			y++;
			X--;
			if (X == 0)
				break;
		}
	}
	cout << x << "/" << y << '\n';

	return 0;
}