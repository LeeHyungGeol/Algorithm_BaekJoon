#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

ll Answer;
int B;
string N;

int main() {
	cin >> N >> B;

	for (int i = N.length() - 1, j = 0; i >= 0; --i, ++j) {
		if (isdigit(N[i])) {
			Answer += (ll)(N[i] - '0') * pow(B, j);
		}
		else {
			Answer += (ll)(N[i] - 'A' + 10) * pow(B, j);
		}
	}

	cout << Answer << '\n';

	return 0;
}