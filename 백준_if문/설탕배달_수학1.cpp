#include <iostream>
using namespace std;

int main() {

	int n, y = 0, tmp = 0, result = 0;
	cin >> n;
	y = n / 5;
	while (y >= 0) {
		tmp = 0;
		tmp = n - (5 * y);
		if (tmp % 3 == 0) {
			cout << y + (tmp / 3) << '\n';
			return 0;
		}
		y--;
	}
	cout << "-1" << '\n';
	return 0;
}

//
//int solution(int& N) {
//
//	int y = N / 5; //5로 나누었을때 몫
//
//	while (y >= 0) {   //5로 나누었을떄의 몫을 하나씩 감소하면서 계산
//		int tmp = N - (5 * y);   //tmp는 전체 에서 5*몫을 뺀 값
//		if (tmp % 3 == 0) {    //tmp가 3으로 나눈 나머지가 0인 경우(0도 포함됨)
//			return y + (tmp / 3);   //5의 개수 + 3의 개수
//		}
//		y--;
//	}
//	return -1;
//}
//
//int main(void) {
//	int N;
//	int result;
//	cin >> N;
//
//	result = solution(N);
//
//	cout << result << '\n';
//	return 0;
//}
