#include <iostream>
#include <set>

using namespace std;

set<int> Arr;

int main() {
	for (int i = 0; i < 28; ++i) {
		int n;
		cin >> n;
		Arr.insert(n);
	}

	for (int i = 1; i <= 30; ++i) {
		if (Arr.find(i)==Arr.end()) {
			cout << i << '\n';
		}
	}

	return 0;
}