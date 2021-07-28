#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer;
vector<int> people;

int main() {
	cin >> N;

	people.resize(N, 0);

	for (int i = 0; i < N; ++i) {
		cin >> people[i];
	}

	sort(people.begin(), people.end());

	int cnt = 0;

	for (int x : people) {
		++cnt;

		if (cnt >= x) {
			++answer;
			cnt = 0;
		}
	}

	cout << answer << '\n';

	return 0;
}