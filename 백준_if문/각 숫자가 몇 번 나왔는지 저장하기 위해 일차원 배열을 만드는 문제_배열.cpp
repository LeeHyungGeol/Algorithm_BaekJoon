#include <iostream>
using namespace std;

int main() {
	int A, B, C, num = 0, array[10] = {0,}, x = 0;
	cin >> A >> B >> C;

	num = A * B * C;

	while (num != 0) {
		array[num % 10]++;
		num = num / 10;
	}
	
	for (int i = 0; i < 10; i++) {
		cout << array[i] << '\n';
	}

	return 0;
}
