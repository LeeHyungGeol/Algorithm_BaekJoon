#include <iostream>
using namespace std;

int main() {

	int N, M = -1;
	double sum = 0;
	cin >> N;
	int* p = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> p[i];
		if (p[i] > M)
			M = p[i];
	}
	for (int i = 0; i < N; i++) {
		sum += (p[i] / (double)M) * 100;
	}
	cout.precision(9);
	cout << sum / (double)N << '\n';
	return 0;
}