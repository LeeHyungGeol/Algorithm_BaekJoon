#include <iostream>
using namespace std;

int main() {

	int sum=0, i=0;

	while (i < 10) {
		++i;
		if (i % 2 == 1)
			continue;
		sum += i;
	}
	cout << sum << '\n';
	return 0;
}