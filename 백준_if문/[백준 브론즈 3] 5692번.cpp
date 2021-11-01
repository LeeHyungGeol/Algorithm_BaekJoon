#include <iostream>

using namespace std;

int factorial(int n);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	while (cin >> n) {
		if (n == 0) break;
		int i = 1, result = 0;
		while (n) {
			int temp = n % 10;
			n /= 10;
			result += (temp * factorial(i));
			++i;
		}
		cout << result << '\n';
	}
	return 0;
}

int factorial(int n) {
	if (n == 0 || n == 1) return 1;
	return n * factorial(n - 1);
}