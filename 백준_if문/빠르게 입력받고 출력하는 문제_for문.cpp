#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

	int i, num1, num2, count;

	cin >> count;
	for (i = 0; i < count; i++) {
		cin >> num1 >> num2;
		cout << num1 + num2 << '\n';
	}

	return 0;
}