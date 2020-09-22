#include <iostream>
using namespace std;

int arithmeticSequence(int n);
int main() {

	int n, count = 0;
	cin >> n;
	
	if (n < 100) {
		cout << n << '\n';
		return 0;
	}
	count = 99;
	for (int i = 100; i <= n; i++) {
		if (arithmeticSequence(i) == 1) {
			count++;
		}
	}
	cout << count << '\n';
	return 0;
}
int arithmeticSequence(int n) {
	
	int input = n, i = 0, count = 0, check = 1;
	while (input != 0) {

		input = input / 10;
		count++;
	}
	int* arr = new int[count];
	while (n != 0) {
		arr[i] = n % 10;
		n = n / 10;
		i++;
	}
	int d = arr[1] - arr[0];
	for (int i = 2; i <= (count - 1); i++) {
		if ((arr[i] - arr[i - 1]) != d)
			check = 0;
	}

	return check;
}