//동전의 조건이 특별해서 동적 프로그래밍보다 빠르게 답을 찾을 수 있는 문제
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	vector<int> v;
	int x, N, K, result = 0;
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), greater<int>());//내림차순 정렬
	for (int i = 0; i < N; ++i) {
		if (K / v[i] > 0) {
			result += K / v[i];
			K %= v[i];
		}
	}
	cout << result << '\n';
	return 0;
}