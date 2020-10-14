#include <iostream>
using namespace std;

int main() {

	int N, first = 0, second = 0, result=0, newN = 0, cnt = 0;
	cin >> N;
	newN = N;
	while (true) {
		first = newN / 10;
		second = newN % 10;
		result = first + second;
		newN = (second * 10) + (result % 10);
		cnt++;
		if (newN == N)
			break;
	}
	cout << cnt << '\n';
	return 0;
}