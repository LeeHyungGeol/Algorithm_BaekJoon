#include <iostream>
using namespace std;

int main() {
	int N, X, i, num;

	cin >> N >> X;

	for (i = 0; i < N; i++) {
		cin >> num;
		if (num < X)
			cout << num << " ";
	}
	cout << '\n';
}