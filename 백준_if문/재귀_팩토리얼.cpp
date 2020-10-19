// 재귀_factorial 구현 문제
#include <iostream>	
using namespace std;

int factorial(int n);
int main() {

	int N;
	cin >> N;
	cout << factorial(N) << '\n';

}
int factorial(int n) {

	if (n == 0 || n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}