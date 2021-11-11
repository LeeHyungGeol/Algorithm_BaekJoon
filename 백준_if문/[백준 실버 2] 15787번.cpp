#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M;
vector<int> Arr;
set<int> Set;

int main() {
	cin >> N >> M;

	Arr.assign(N + 1, 0);

	for (int i = 0; i < M; ++i) {
		int cases, index, x;
		cin >> cases;

		if (cases == 1) {
			cin >> index >> x;
			Arr[index] |= (1 << (x - 1));
		}
		else if (cases == 2) {
			cin >> index >> x;
			Arr[index] &= ~(1 << (x - 1));
		}
		else if (cases == 3) {
			cin >> index;
			Arr[index] = Arr[index] << 1;
			Arr[index] &= ((1 << 20) - 1);
		}
		else if (cases == 4) {
			cin >> index;
			Arr[index] = Arr[index] >> 1;
		}
	}

	for (int i = 1; i <= N; ++i) {
		Set.insert(Arr[i]);
	}

	cout << Set.size() << '\n';

	return 0;
}