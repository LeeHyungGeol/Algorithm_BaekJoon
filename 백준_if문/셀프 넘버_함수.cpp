#include <iostream>
using namespace std;

int d(int n);
int main() {

	int count = 0;
	
	for (int i = 1; i <= 10000; i++) {
		for (int j = 1; j <= i; j++) {
			if (d(j) == i) {
				count++;
			}
		}
		if (count == 0) {
			cout << i << '\n';
		}
		count = 0;
	}


	return 0;
}
int d(int n) {
	
	int input = n, sum = 0, result = 0;
	while (input != 0) {
	
		sum += input % 10;
		input = input / 10;
	}
	result = sum + n;

	return result;
}