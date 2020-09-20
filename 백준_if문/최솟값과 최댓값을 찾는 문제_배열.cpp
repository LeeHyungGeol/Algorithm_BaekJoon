#include <iostream>
using namespace std;

int main() {

	int N, max= -1000000, min = 1000000;
	cin >> N;
	int* p = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> p[i];
		if (p[i] > max)
			max = p[i];
		if (p[i] < min)
			min = p[i];
	}
	cout << min << " " << max << '\n';

	/*int n;
	cin >> n;

	int num[n + 1];
	int min = 1000000;
	int max = -1000000;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (min > num[i]) {
			min = num[i];
		}
		if (max < num[i]) {
			max = num[i];
		}
	}

	cout << min << " " << max << "\n";*/


	return 0;
}