#include <iostream>
using namespace std;

int main() {

	int num, i, result = 0;

	cin >> num;

	for (i = 1; i <= num; i++) {
		result += i;
	}

	cout << result << endl;
	return 0;
}