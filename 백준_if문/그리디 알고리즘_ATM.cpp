//기다리는 시간의 합을 최소화하는 문제
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	vector<int> v;
	int N, x, sum = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			sum += v[j];
			//sum += v[i]*(N-i); //이렇게 해주면 1차원 배열 사용 가능
		}
	}
	cout << sum << '\n';
	return 0;
}