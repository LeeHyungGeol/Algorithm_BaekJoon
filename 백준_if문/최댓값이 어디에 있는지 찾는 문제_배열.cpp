#include <iostream>
using namespace std;

int main() {

	int n, max=0, index=1;
	for (int i = 0; i < 9; i++) {
		cin >> n;
		if (n > max) {
			max = n;
			index = i + 1;
		}
	}
	cout << max << '\n' << index << '\n';
	
	return 0;
}