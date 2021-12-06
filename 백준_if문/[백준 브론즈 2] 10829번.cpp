#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long N;

void numToBinary2(long long n);
string numToBinary(long long n);

int main() {
	cin >> N;

	numToBinary2(N);

	cout << '\n';

	return 0;
}

void numToBinary2(long long n) {
	if (n != 1) numToBinary2(n / 2);
	cout << n % 2;
}

string numToBinary(long long n) {
	string ret;

	while (n) {
		ret += (n % 2)+'0';
		n /= 2;
	}

	reverse(ret.begin(), ret.end());

	return ret;
}