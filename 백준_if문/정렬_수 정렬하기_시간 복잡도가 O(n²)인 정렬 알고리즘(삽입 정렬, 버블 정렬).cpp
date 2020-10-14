#include <iostream>
using namespace std;

int main() {

	int arr[1001] = { 0 };
	int N, tmp, n;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - (i + 1); ++j) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << arr[i] << '\n';
	}


	return 0;
}