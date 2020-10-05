#include <iostream>
#include <cmath>
using namespace std;

void rHanoi(int n, int first, int second, int third);
int main() {

	int N;
	cin >> N;
	cout << (int)pow(2, N) - 1 << '\n'; //(1 << n), pow()는 실수형으로 계산
	rHanoi(N, 1, 2, 3);

	return 0;
}
void rHanoi(int n, int first, int second, int third) {
	
	if (n == 1)
		cout << first << " " << third << '\n';
	else {
		rHanoi(n - 1, first, third, second);
		cout << first << " " << third << '\n';
		rHanoi(n - 1, second, first, third);
	}
}
//1. 1번기둥의 n - 1개를 2번기둥으로 이동. 1번기둥엔 제일 큰 원판 하나만 남음.
//2. 1번기둥의 제일 큰 원판을 3번기둥으로 이동.
//3. 2번기둥의 n - 1개의 원판을 모두 3번기둥으로 이동.