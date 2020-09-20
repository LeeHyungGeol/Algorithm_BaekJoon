#include <iostream>
using namespace std;

int main() {

	int n, sum = 0, cnt = 0;
	double avg = 0;
	cin >> n;

	int** mat = new int* [n];
	for (int i = 0; i < n; i++)
		mat[i] = new int[1001];

	for (int i = 0; i < n; i++) {
		cin >> mat[i][0];

		for (int j = 1; j <= mat[i][0]; j++) {
			cin >> mat[i][j];
			sum += mat[i][j];
		}

		avg = sum / mat[i][0];

		for (int j = 1; j <= mat[i][0]; j++) {
			if (mat[i][j] > avg)
				cnt++;
		}
		cout << fixed;
		cout.precision(3);		
		cout << (cnt / (double)(mat[i][0])) * 100 << "%" << '\n';
		cnt = 0;
		avg = 0;
		sum = 0;

	}

	return 0;
}