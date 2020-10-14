#include <iostream>
using namespace std;

int main() {

	int A, B, V, cnt = 0;
	cin >> A >> B >> V;
	V -= A;
	if (V % (A - B) == 0) {
		cnt = V / (A - B);
		cout << cnt + 1 << '\n';
	}
	else {
		cnt = V / (A - B);
		cout << cnt + 2 << '\n';
	}
	return 0;
}