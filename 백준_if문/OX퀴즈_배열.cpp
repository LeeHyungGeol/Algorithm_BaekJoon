#include <iostream>
using namespace std;

int main() {

	int n, sum = 0;
	cin >> n;
	int cntO = 0, cntX = 0;

	char** mat = new char* [n];
	for (int i = 0; i < n; i++) {
		mat[i] = new char[80];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 80; j++) {
			mat[i][j] = 'a';
		}
	}

	for (int i = 0; i < n; i++) {
			cin >> mat[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 80; j++) {
			if (mat[i][j] == 'O') {
				cntO++;
				sum += cntO;
			}
			else if (mat[i][j] == 'X') {
				cntO = 0;
			}
			else {
				cntO = 0;
				cout << sum << '\n';
				sum = 0;
				break;
			}
		}
	}

	return 0;
}