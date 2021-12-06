#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int L, r = 31, M = 1234567891;
long long Answer, j = 1;
string Str;

int main() {
	cin >> L >> Str;

	for (int i = 0; i < Str.length(); ++i) {
		Answer += (long long)((Str[i] - 'a' + 1) * j) % M;
		Answer %= (long long)M;
		j *= r;
		j %= M;
	}

	cout << Answer << '\n';

	return 0;
}