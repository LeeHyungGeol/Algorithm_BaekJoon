#include <iostream>
using namespace std;
/*
카운팅정렬(Counting Sort) - 값을 비교해서 정렬하는 방식이라기 보다는 값의 갯수를 세고 그 갯수에 따라서 위치를 설정해주는 방식
즉, 데이터들간의 크기를 비교하거나 그런 정렬 방식이 아니다.
https://hongku.tistory.com/155
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, n, count[10001] = { 0 };
	cin >> N;
	
	for (int i = 1; i <= N; ++i) {
		cin >> n;
		count[n]++;
	}

	for (int i = 1; i <= 10000; ++i) {//입력 받은 수(여기서는 n)의 최대숫자로 하자.
		if (count[i] != 0) {
			for (int j = 1; j <= count[i]; ++j) {
				cout << i;
				cout << '\n';
			}
		}
	}

	return 0;
}