#include <iostream>
using namespace std;

int main() {

	int num1, num2;

	cin >> num1 >> num2;

	if (num1 == 0) {
		if (num2 < 45)
			cout << "23 " << (num2 + 15) << endl;
		else if (num2 > 45)
			cout << "0 " << (num2 - 45) << endl;
		else 
			cout << num1 << " 0" << endl;
	}
	else {

		if (num2 < 45)
			cout << (num1 - 1) << " " << (num2 + 15) << endl;
		else if (num2 > 45)
			cout << num1 << " " << (num2 - 45) << endl;
		else
			cout << num1 << " 0" << endl;
	}

	return 0;
}