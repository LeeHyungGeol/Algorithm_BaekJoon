// 이분 탐색을 이용한 파라메트릭 서치 문제
// 파라메트릭 서치(Parametric Search) : 최적화 문제를 결정 문제로 바꾸어 해결하는 기법
// -> 이분 탐색으로 결정 문제를 해결하면서 범위를 좁혀갈 수 있다.

// K개의 랜선으로 N개의 랜선을 만든다.
// N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다.
// 최대 랜선의 길이를 구하자.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int K, N;
vector<int> lanWire;

int main() {
	cin >> K >> N;

	for (int i = 0; i < K; ++i) {
		int temp;
		cin >> temp;
		lanWire.push_back(temp);
	}

	ll start = 0;
	ll end = 2147483647;
	ll result = 0;

	while (start <= end) {
		ll sum = 0;

		ll mid = (start + end) / 2;

		for (int i = 0; i < K; ++i) {
			ll count = lanWire[i] / mid;
			
			if (count) {
				sum += count;
			}
		}

		// N개 보다 작다는 의미는 길이(mid)를 너무 크게 정해서 랜선을 많이 못 잘라서 발생한 것이므로
		// (왼쪽 부분 탐색)을 의미
		if(sum < N) {
			end = mid - 1;
		}
		else {
			result = mid;
			start = mid + 1;
		}
	}

	cout << result << '\n';

	return 0;
}