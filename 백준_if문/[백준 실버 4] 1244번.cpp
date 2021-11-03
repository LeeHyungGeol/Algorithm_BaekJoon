#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> Arr;

int main() {
	cin >> N;

	Arr.assign(N+1, 0);

	for (int i = 1; i <= N; ++i) {
		cin >> Arr[i];
	}

	cin >> M;

	for (int i = 0; i < M; ++i) {
		int gender, num;
		cin >> gender >> num;

		if (gender == 1) {
			int i = 1, mul = num;
			while (mul <= N) {
				if (Arr[mul]) Arr[mul] = 0;
				else Arr[mul] = 1;
				++i;
				mul = num * i;
			}
		}
		else {
			int left = num, right = num;
			while (Arr[left] == Arr[right]) {
				if (!(1 <= left && right <= N)) break;
				--left;
				++right;
			}

			++left;
			--right;

			for (int i = left; i <= right; ++i) {
				if (Arr[i]) Arr[i] = 0;
				else Arr[i] = 1;
			}
		}
	}

	for (int i = 1, j=1; i <= N; ++i, ++j) {
		cout << Arr[i] << ' ';
		if (j == 20) {
			j = 0;
			cout << '\n';
		}
	}
	cout << '\n';

	return 0;
}