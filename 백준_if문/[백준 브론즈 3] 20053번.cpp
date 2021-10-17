#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, T;
vector<int> Arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> N;
		Arr.clear();

		for (int i = 0; i < N; ++i) {
			int n;
			cin >> n;
			Arr.push_back(n);
		}
		
		sort(Arr.begin(), Arr.end());

		cout << Arr.front() << " " << Arr.back() << '\n';
	}

	return 0;
}