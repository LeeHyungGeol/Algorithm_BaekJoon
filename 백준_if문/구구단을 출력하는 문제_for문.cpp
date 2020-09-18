#include <iostream>
using namespace std;

int main() {
	
	int num1, i;

	cin >> num1;

	for (i = 1; i <= 9; i++) {
		cout << num1 << " * " << i << " = " << num1 * i << endl;
	}

	return 0;
}