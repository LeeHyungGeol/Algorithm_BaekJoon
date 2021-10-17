#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> Arr;

int main() {
	cin >> N >> M;

	Arr.resize(N + 1, 0);

	for (int i = 1; i <= N; ++i) {
		cin >> Arr[i];
	}

	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			Arr[b] = c;
		}
		else if (a == 2) {
			for (int j = b; j <= c; ++j) {
				if (Arr[j]) {
					Arr[j] = 0;
				}
				else {
					Arr[j] = 1;
				}
			}
		}
		else if (a == 3) {
			for (int j = b; j <= c; ++j) {
				Arr[j] = 0;
			}
		}
		else if (a == 4) {
			for (int j = b; j <= c; ++j) {
				Arr[j] = 1;
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		cout << Arr[i] << ' ';
	}
	cout << '\n';

	return 0;
}