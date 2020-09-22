#include <iostream>
#include <vector>
using namespace std;

long long sum(std::vector<int>& a);
int main() {

	int n, x;
	long long total = 0;
	cin >> n;
	std::vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}
	total = sum(a);

	cout << total << '\n';

	return 0;
}
long long sum(std::vector<int>& a) {
	long long sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i];
	}
	return sum;
}