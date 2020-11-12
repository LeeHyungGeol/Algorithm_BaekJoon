//의외로 이분 탐색으로 풀 수 있는 놀라운 문제 1 == 생각하기 정말 어려운 문제
//https://steady-coding.tistory.com/20
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	int start = 1, end = K;
	int result = -1;
	while (start <= end) {
		int cnt = 0;
		int mid = (start + end) / 2;
		for (int i = 1; i <= N; ++i) {
			cnt += min(mid / i, N); // .mid보다 작은 숫자의 갯수를 더한다. mid에다가 각 행의 숫자(i)를 나눈다. 다만 몫이 N보다 큰 경우가 있기 때문에 min함수를 사용한다.
		}
		if (cnt < K)
			start = mid + 1;
		else {
			result = mid;
			end = mid - 1;
		}
	}
	cout << result << '\n';
	return 0;
}