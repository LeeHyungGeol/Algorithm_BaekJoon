#include <iostream>
using namespace std;

long long int arr[101] = { 1,1,1,1, };
long long int padovanSequence(long long int n);

int main() {
	int T, input;
	for (int i = 4; i <= 100; ++i) {
		arr[i] = -1;
	}
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> input;
		padovanSequence(input);
		cout << arr[input] << '\n';
	}
	return 0;
}
long long int padovanSequence(long long int n) {
	if (n <= 3) {
		return 1;
	}
	else {
		if (arr[n] != -1)
			return arr[n];
		else {
			arr[n] = padovanSequence(n - 2) + padovanSequence(n - 3);
			return arr[n];
		}
	}
}