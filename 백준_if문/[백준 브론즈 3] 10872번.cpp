#include <iostream>

using namespace std;

int N;

int factorial(int n);

int main() {
	cin >> N;

	cout << factorial(N) << '\n';

	return 0;
}

int factorial(int n) {
	if (n == 0 || n == 1) return 1;
	else return n * factorial(n - 1);
}