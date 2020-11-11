//흔히 parametric search라고도 부르는, 이분 탐색을 응용하여 최솟값이나 최댓값을 찾는 테크닉을 배우는 문제
//파라메트릭 서치(parametric search) : 최적화 문제를 결정 문제로 바꾸어 해결하는 기법
//결정 문제: '예' 혹은 '아니오'로 답하는 문제
//'원하는 조건을 만족하는 가장 알맞은 값을 찾는 문제'에 파라메트릭 서치(parametric search)를 사용한다.
#include <iostream>
#include <vector>
using namespace std;

int main() {

	int K, N, x;
	cin >> K >> N;
	vector<int> v;
	for (int i = 0; i < K; ++i) {
		cin >> x;
		v.push_back(x);
	}
	long long int start = 0, end = 2147483647;//2^31-1
	long long int mid = 0, cnt = 0, result = 0;

	while (start <= end) {
		cnt = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < K; ++i) {
			cnt += (v[i] / mid);
		}
		if (cnt < N)
			end = mid - 1;
		else { //N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다. 이것이 문제의 조건이었기 때문에, cnt의 값이 N 이상이면 된다.
			result = mid; //따라서 else if(cnt==N)의 조건문은 필요없다.
			start = mid + 1;
		}
	}
	cout << result << '\n';
	return 0;
}