//재귀_피보나치 구현
#include <iostream>
using namespace std;

int fibonachi(int n);
int main() {

	int n;
	cin >> n;
	cout << fibonachi(n) << '\n';
}
int fibonachi(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return fibonachi(n - 1) + fibonachi(n - 2);
}