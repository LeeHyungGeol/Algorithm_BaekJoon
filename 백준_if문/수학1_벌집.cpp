#include <iostream>
using namespace std;

int main() {
	int N, x = 1, cnt = 1, tmp;
	cin >> N;
	tmp = 1;
	while (true) {
		if (N <= tmp)
			break;
		tmp += 6 * x;
		x++;
		cnt++;
	}
	cout << cnt << '\n';

	return 0;
}