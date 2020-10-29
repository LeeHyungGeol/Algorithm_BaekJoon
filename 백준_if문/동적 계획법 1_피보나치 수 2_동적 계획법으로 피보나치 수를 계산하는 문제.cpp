#include <iostream>
using namespace std;
//대부분의 언어에서 일반 정수형은 32bit이기 때문에 2의 범위를 표현하지 못한다. 64bit 정수형을 쓰라는 의도
//답의 크기가 int범위를 넘기 때문에 long long으로 바꿔야 한다. 
//Dynamic Programming(동적 계획법) 해결에 메모이제이션과 반복문을 사용하는 방법 양쪽 다 알아두자.
int main() {

	int N;
	cin >> N;
	long long int arr[91];
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= N; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << arr[N] << '\n';
	return 0;
}
