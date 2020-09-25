#include <iostream>
using namespace std;

int main() {

	int A, B, C, x = -1;
	cin >> A >> B >> C;
    if (B >= C) {
        cout << x << '\n';
        return 0;
    }
	x = (A / (C - B)) + 1;
	cout << x << '\n';
	return 0;
}
