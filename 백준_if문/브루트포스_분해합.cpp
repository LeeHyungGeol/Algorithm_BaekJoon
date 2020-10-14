#include <iostream>
#include <vector>
using namespace std;

int decomposition(int n);//분해합 구하는 함수
int main() {

	int N, result = 0;
	cin >> N;
	for (int M = 1; M <= N; ++M) {
		result = decomposition(M);
		if (result == N) {
			cout << M << '\n';//정수 N의 생성자가 M이다.
			return 0;
		}
	}
	cout << "0" << '\n';
	return 0;
}
int decomposition(int n) {
	int tmp = n, sum = 0;
	vector<int> v; //자리수들을 저장하기 위한 벡터

	while (true) {
		if (tmp == 0)
			break;
		v.push_back(tmp % 10);
		tmp = tmp / 10;
	}
	for (int i = 0; i < v.size(); ++i) {
		sum += v[i];
	}
	return n + sum;
}