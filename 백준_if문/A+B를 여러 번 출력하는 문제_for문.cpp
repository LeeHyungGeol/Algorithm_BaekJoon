#include <iostream>
using namespace std;

int main() {

	int count, i, num1, num2;

	cin >> count;

	for (i = 0; i < count; i++) {
		cin >> num1 >> num2;
		cout << num1 + num2 << endl;
	}

	return 0;
}